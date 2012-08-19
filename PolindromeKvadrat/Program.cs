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

            List<string> inputStrings = new List<string>();

            List<MatrixPoint> biggestSquare = (List<MatrixPoint>)(polindromeDetector.GetBiggestSquare(inputStrings));

            Console.WriteLine("The biggest polindrome cordinates:");
            foreach (MatrixPoint point in biggestSquare)
                Console.WriteLine("X: {0} Y:{1}", point.X, point.Y);
        }
    }
}
