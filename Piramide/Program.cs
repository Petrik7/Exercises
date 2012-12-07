using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Piramide
{
    class StringPiramide
    {
        public static void DisplayAsTriangle(string str)
        {
	        int len = str.Length;
	        int median = len / 2;

	        for (int i = 0; i <= median; ++i)
	        {
		        for (int spaceCounter = 0; spaceCounter < median - i; ++spaceCounter)
			         Console.Write(" ");

		        for (int j = median - i; j <= median + i; ++j)
                    if(j < len)
			            Console.Write(str[j]);

		        Console.Write("\n");
	        }
        }

        private static void PrintSpaces(int num)
        { 
            StringBuilder spaces = new StringBuilder();
            for(int i = 0; i < num; ++i)
                spaces.Append(" ");

            Console.Write(spaces.ToString());
        }

        public static void Print(string text)
        {
            int half = text.Length/2;
            int numOfLetters = 1;

            for (int i = half; i >= 0; --i, numOfLetters += 2)
            {
                PrintSpaces(i);
                for (int l = 0; l < numOfLetters; ++l)
                    if (i + l < text.Length)
                        Console.Write(text[i + l]);

                Console.Write("\n");
            }
        
        
        }
        
    }

    class Program
    {
        static void Main(string[] args)
        {
            StringPiramide.Print("abcde");
            StringPiramide.Print("This is the test piramide string");

            StringPiramide.DisplayAsTriangle("abcde");
            StringPiramide.DisplayAsTriangle("This is the test piramide string");

        }
    }
}
