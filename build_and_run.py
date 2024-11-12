import os

def main():
    os.system('mkdir build')
    os.chdir('./build')
    # Generates unix make files instead of the Windows equivelent
    os.system('cmake -G "Unix Makefiles" .. && make -j4 && ./ScreenCreator')

if __name__ == "__main__":
    main()
