using System;
using System.Collections.Generic;

namespace simple_assembler_interpreter
{
    // Our simple Assembler just have 4 statement
    public enum TokenType
    {
        T_MOV,
        T_INC,
        T_DEC,
        T_JNZ,
        T_IDENT,
        T_CONST,
        T_EOF
    }

    public class Token
    {
        public Token ()
	    {

	    }

        public Token (TokenType type, string text, int value)
	    {
            Type = type;
            Text = text;
            Value = value;
	    }

        public TokenType Type;
        public string Text = "";
        public int Value;
    }

    public static class Program
    {
        public static void Main()
        {
            Interpret(new[] { "mov a -10", "mov b a", "inc a", "dec b", "jnz a -2" });
        }

        static Dictionary<string,int> VariablesTable = new Dictionary<string,int>();

        static int _index = 0;
        static string _buffer = "";
        static Token _current_token = new();

        static char _ch
        {
            get
            {
                return _buffer[_index];
            }
        }

        static int GetVariable(string name)
        {
            if (!VariablesTable.Any(a => a.Key == name))
                CreateVariable(name, 0);
            return VariablesTable[name];
        }
    
        static void CreateVariable(string name, int val)
        {
            VariablesTable.Add(name,val);
        }

        static void EditVariable(string name, int newVal)
        {
            VariablesTable[name] = newVal;
        }

        static void Next_char()
        {
            _index++;
        }

        static void Skip()
        {
            while (char.IsWhiteSpace(_ch))
                Next_char();
        }
        
        static void Open_buffer(string [] program)
        {
            _buffer = string.Join('\n', program);
            _buffer += '\0';
        }

        static int Scan_digit()
        {
            int sign = 1;
            if (_ch == '-')
            {
                sign = -1;
                Next_char();
            }
            int res = _ch - '0';
            Next_char();
            while (char.IsDigit(_ch))
            {
                res *= 10 + (_ch - '0');
                Next_char();
            }
            return res * sign;
        }

        static string Scan_ident()
        {
            string res = _ch.ToString();
            Next_char();
            while (char.IsLetter(_ch))
            {
                res += _ch.ToString();
                Next_char();
            }
            return res;
        }

        static TokenType Guess_Text_type(string text)
        {
            if (text == "mov")
                return TokenType.T_MOV;
            else if (text == "jnz")
                return TokenType.T_JNZ;
            else if (text == "inc")
                return TokenType.T_INC;
            else if (text == "dec")
                return TokenType.T_DEC;
            return TokenType.T_IDENT;
        }

        static void Lex()
        {
            Skip();
            if (_ch == '\0')
            {
                _current_token.Type = TokenType.T_EOF;
            } 
            else if (char.IsDigit(_ch) || _ch == '-')
            {
                _current_token.Value = Scan_digit();
                _current_token.Type = TokenType.T_CONST;
            }
            else if (char.IsLetter(_ch))
            {
                _current_token.Text = Scan_ident();
                _current_token.Type = Guess_Text_type(_current_token.Text);
            }
        }

        static void Move_Prev_line()
        {
            int passed = 0;
            while (passed < 2)
            {
                if (_index == 0)
                    break;
                _index--;
                if (_ch == '\n')
                    passed++;
            }
            _index++;
        }

        static void Move_Next_line()
        {
            while (true)
            {
                _index++;
                if (_ch == '\n' || _index >= _buffer.Length)
                    break;
            }
            _index++;
        }

        static void Match(TokenType type)
        {
            if (_current_token.Type != type)
                Console.WriteLine($"{type} Expected");
        }

        static void Move_ins()
        {
            Lex();
            Match(TokenType.T_IDENT);
            string name = _current_token.Text;
            Lex();
            if (_current_token.Type == TokenType.T_CONST)
            {
                EditVariable(name, _current_token.Value);
            }
            else if (_current_token.Type == TokenType.T_IDENT)
            {
                EditVariable(name, GetVariable(_current_token.Text));
            }
        }

        static void Inc_ins()
        {
            Lex();
            Match(TokenType.T_IDENT);
            string name = _current_token.Text;
            var variable = GetVariable(name);
            EditVariable(name, ++variable);
        }

        static void Dec_ins()
        {
            Lex();
            Match(TokenType.T_IDENT);
            string name = _current_token.Text;
            var variable = GetVariable(name);
            EditVariable(name, --variable);
        }

        static void Jnz_ins()
        {
            Lex();
            Match(TokenType.T_IDENT);
            var variable = GetVariable(_current_token.Text);
            Lex();
            int times = 0;
            if (_current_token.Type == TokenType.T_CONST)
                times = _current_token.Value;
            else if (_current_token.Type == TokenType.T_IDENT)
                times = GetVariable(_current_token.Text);
            if (variable != 0)
            {
                if (_current_token.Value < 0)
                {
                    for (int i = 0; i < times * -1; i++)
                        Move_Prev_line();
                } 
                else
                {
                    for (int i = 0; i < times; i++)
                        Move_Next_line();
                }
            }
        }

        public static Dictionary<string, int> Interpret(string[] program)
        {
            Open_buffer(program);
            Lex();
            while (_current_token.Type != TokenType.T_EOF)
            {
                switch (_current_token.Type)
                {
                    case TokenType.T_MOV :
                        Move_ins();
                        break;
                    case TokenType.T_INC :
                        Inc_ins();
                        break;
                    case TokenType.T_DEC :
                        Dec_ins();
                        break;
                    case TokenType.T_JNZ :
                        Jnz_ins();
                        break;
                }
                Lex();
            }
            foreach (var item in VariablesTable)
            {
                Console.WriteLine($"{item.Key} : {item.Value}");
            }
            return VariablesTable;
        }

    }
}
