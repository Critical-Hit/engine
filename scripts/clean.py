from subprocess import call

def removeFile(filename):
    call(["rm", "-rf", filename])

# Add any additional files you wish to clean here
filesToRemove = ["obj", "bin", "*.suo", "*.sdf"]

def main():
    print "Cleaning Directory..."
    for file in filesToRemove:
        removeFile(file) 

if __name__ == "__main__":
    main()
