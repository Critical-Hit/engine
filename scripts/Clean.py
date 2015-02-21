from subprocess import call
import os
import os.path
import glob
import shutil

# Add any additional files you wish to clean here
FILES_TO_REMOVE = ["*.suo", "*.sdf"]
FOLDERS_TO_REMOVE = ["obj"]


def remove_file(filename):
    for f in glob.glob(filename):
        os.remove(f)


def remove_folder(folder):
    for f in glob.glob(folder):
        shutil.rmtree(f)


def main():
    print("Cleaning Directory...")
    if os.path.exists("Makefile"):
        try:
            call(["make", "clean"])
        except:
            pass
    for file in FILES_TO_REMOVE:
        remove_file(file)
    for folder in FOLDERS_TO_REMOVE:
        remove_folder(folder)

if __name__ == "__main__":
    main()
