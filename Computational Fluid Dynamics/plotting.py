import matplotlib.pyplot as plt
import pandas as pd
import argparse



def plotting(args):
    name = args.DataName+args.DataType
    print(name)
    data = pd.read_csv(name)
    x = data.iloc[:,0]
    y = data.iloc[:,1]
    plt.plot(x,y)
    plt.title(args.DataName)
    plt.show()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-d", "--DataName",type = str,help ="Name der Datei")
    parser.add_argument("-t", "--DataType", type = str, help = "Datatype: .csv, .xlsx, etc")
    args = parser.parse_args()
	
    plotting(args)
    print("Plotting: ")


if __name__ == "__main__":
    main()

