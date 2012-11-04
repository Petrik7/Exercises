using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MatrixCs
{
    class Printer
    {
        public static void circularWay (int[][]  matrix) 
	    {
            int numColumns = matrix[0].Length;
		    int[,] hash = new int[matrix.Length, numColumns];
            int[][] moves = new int[][] { new int[] { 0, 1 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { -1, 0 } };
		    int i = 0;	
            int j = 0;
		    int m = 0;
		    int row;
            int column;

		    while (hash[i,j] == 0) 
		    {
			    row = i + moves[m][0];
			    column = j + moves[m][1];

			    if ((row < matrix.Length) && (column < matrix[0].Length)
				    && (row >= 0) && (column >= 0)
				    && (hash[row,column] == 0)) 
			    {
				    Console.Write( matrix[i][j]+" ");
				    hash[i,j] = 1;
				    i = row;
				    j = column;
			    } 
			    else 
			    {
				    m++;
				    if (m > 3) 
					    m = 0;
				    row = i + moves[m][0];
				    column = j + moves[m][1];
				    if ((hash[row,column] != 0)) 
				    {
                        Console.Write(matrix[i][j] + " ");
					    hash[i,j] = 1;
				    }
			    }
		    }
        }
    }
}
