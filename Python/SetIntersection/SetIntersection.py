if __name__ == '__main__':
    count = int(input().strip())
    english = list(map(int, input().rstrip().split()))
    count2 = int(input().strip())
    french = list(map(int, input().rstrip().split()))
    print ( len(list(set(english) & set(french))))