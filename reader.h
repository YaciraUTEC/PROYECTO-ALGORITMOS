#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "blockchain.h"

class Master {
private:
    Blockchain blockchain;
    int MaxRecords;
public:
    Master(int _MaxRecords) : MaxRecords(_MaxRecords) {}

    void addCsvData(const string& file){
        ifstream inputFile(file);

        string header;
        getline(inputFile, header);
        string line;
        string cliente, lugar, fecha, monto;

        Block block;

        int recordCount = 0;

        while (getline(inputFile, line)) {
            stringstream ss(line);
            getline(ss, cliente, ',');
            getline (ss, lugar, ',');
            getline (ss, monto, ',');
            getline(ss, fecha, ',');

            block.addRecord(cliente, lugar, stod(monto), fecha);

            recordCount++;

            if (recordCount == MaxRecords) {
                blockchain.addBlock(block);

                Block newBlock;

                block = newBlock;

                recordCount = 0;
            }
        }

        if (recordCount > 0){
            blockchain.addBlock(block);
        }

    }

    void printBlockchain() const {
        blockchain.printBlockchain();
    }

    vector<record> range_search(double lower, double upper) {
        return blockchain.range_search(lower, upper);
    }

    vector<record> searchByClient(const std::string& cliente) {
        return blockchain.search(cliente);
    }

};

#endif // CSV_READER_H
