gcc test-ast.c -fdump-tree-all-graph
dot -Tpng test-ast.c.012t.cfg.dot -o main.png
xdg-open main.png
