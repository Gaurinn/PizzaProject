#include "ExtraFoodRepository.h"
#include <fstream>

ExtraFoodRepository::ExtraFoodRepository()
{
    //ctor
}

ExtraFoodRepository::~ExtraFoodRepository()
{
    //dtor
}

void ExtraFoodRepository::storeExtraFood(const ExtraFood& extrafood){ ///store extra food to binary file
    ofstream fout;
    fout.open("extraFoodBinary.bin", ios::binary|ios::app);
    extrafood.write(fout);
    fout.close();
}

ExtraFood ExtraFoodRepository::retrieveExtraFood(){ ///read extra food from binary file
    ifstream fin;
    fin.open("extraFoodBinary.bin", ios::binary);
    ExtraFood extrafood;
    extrafood.read(fin);
    fin.close();
    return extrafood;
}

vector<ExtraFood> ExtraFoodRepository::retrieveAllExtraFood(){ ///read all extra food from binary file
    vector<ExtraFood> extrafoods;
    ifstream fin;
    fin.open("extraFoodBinary.bin", ios::binary);
    ExtraFood extrafood;
    while(true){
        int filePos = fin.tellg();          //current position in file
        fin.seekg(0, fin.end);              //go to end
        int endPos = fin.tellg();           //end position in file
        if((endPos - filePos) <= 1){        //if true last record read... not enough space left for whole record
            break;
        }
        fin.seekg(filePos);
        extrafood.read(fin);
        extrafoods.push_back(extrafood);
    }
    fin.close();
    return extrafoods;
}
