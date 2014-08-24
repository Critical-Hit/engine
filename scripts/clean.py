from subprocess import call
import os.path

def removeFile(filename):
    call(["rm", "-rf", filename])

# Add any additional files you wish to clean here
filesToRemove = ["obj", "*.suo", "*.sdf"]

def main():
    print ("Cleaning Directory...")
    if os.path.exists("Makefile"):
        try:
            call(["make", "clean"])
        except:
            pass
    for file in filesToRemove:
        removeFile(file) 

if __name__ == "__main__":
    main()
