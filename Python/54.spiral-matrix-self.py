
class Solution:
    def spiralOrder(self, matrix:list) -> list:
        # up = 0
        # down = 0
        # left = 0
        # right = 0
        ret = []
        direct = 0

        rows = len(matrix)
        columns = len(matrix[0])
        print(rows)
        print(columns)
        # nums = rows * columns

        count = 0
        direct = 1
        while count < nums:
            if direct == 1:
                






        return 1



if __name__ == "__main__":
    solu = Solution()
    matrix = [ [ 1, 2, 3 ],
            [ 4, 5, 6 ], 
            [ 7, 8, 9 ]]
    print(matrix)
    ret = solu.spiralOrder(matrix)

    print(ret)