import os

if __name__=="__main__":
    trovato = False

    while(trovato==False):
        os.system("python3 python_string_generator.py 10;./main 5 > output")

        with open("./output") as file:
            lines = [line.rstrip() for line in file]

        #if(lines[-5]=="Il SA è valido."):
        #    print("Apposto")
        #else:
        #    print("trovato l'inghippo")

        if(lines[-5]!="Il SA è valido."):
            print("trovato l'inghippo")
            trovato=True
