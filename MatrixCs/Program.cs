using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MatrixCs
{
    class Program
    {
        static void Main(string[] args)
        {
            int[][] matrix = new int[][] 
            { 
                new int[] { 1,  2,  3,  4}, 
                new int[] { 12, 13, 14, 5}, 
                new int[] { 11, 16, 15, 6}, 
                //new int[] { 10, 9,  8 , 7}
            };

            Printer.circularWay(matrix);
        }
    }
}
