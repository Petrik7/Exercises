using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PolindromeKvadrat
{
    class Program
    {
        static void Main(string[] args)
        {

            PolindromeDetector polindromeDetector = new PolindromeDetector();

            ICollection<string> inputStrings = FileLinesReader.GetLines(@"..\..\inputData.txt");

            List<MatrixPoint> biggestSquare = (List<MatrixPoint>)(polindromeDetector.GetBiggestSquare(inputStrings));

            Console.WriteLine("The biggest polindrome coordinates:");
            foreach (MatrixPoint point in biggestSquare)
                Console.WriteLine("X: {0} Y:{1}", point.X, point.Y);
        }
    }
}
