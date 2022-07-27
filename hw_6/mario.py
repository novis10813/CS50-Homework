"""
try to implement mario in recursive way.
"""

def pyramid(height, fixed_height):
    if height < 0:
        return
    
    if fixed_height != height:
        print(" " * height, end="")
        print("#" * (fixed_height - height), end="")
        
        # mario more
        print("  ", end="")
        print("#" * (fixed_height - height))
    
    return pyramid(height-1, fixed_height)
        

def main():
    height = int(input("Height: "))
    pyramid(height, height)
    
if __name__ == "__main__":
    main()