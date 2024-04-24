using System.Drawing;

var img = new Bitmap("/home/parsa/Pictures/photo_2024-02-22_22-38-27.jpg");
for (int i = 0; i < img.Width; i++)
{
	for (int j = 0; j < img.Height; j++)
	{
		Color pixel = img.GetPixel(i,j);

		if (pixel.R <= 20 && pixel.G <= 20 && pixel.B <= 20)
		{
		}
	}
} 
