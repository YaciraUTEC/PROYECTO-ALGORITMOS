#ifndef BLOCKCHIAN_BLOCK_H
#define BLOCKCHIAN_BLOCK_H

struct Block {
    static int nextId;
    int idblock;
    string nonce;
    ForwardList<record> data;
    string prevHash;
    string hash;

    void addRecord(const string& cliente, const string& lugar, double monto, const string& fecha);
    string calculateHash() const;
    void mineBlock(int difficulty);
};

int Block::nextId = 1;

void Block::addRecord(const string& cliente, const string& lugar, double monto, const string& fecha) {
    record record;
    record.cliente = cliente;
    record.lugar = lugar;
    record.monto = monto;
    record.fecha = fecha;
    data.push_front(record);
}

string Block::calculateHash() const {
    stringstream ss;
    ss << idblock << nonce << prevHash;

    for (const auto& record : data) {
        ss << record.cliente << record.lugar << record.monto << record.fecha;
    }

    EVP_MD_CTX* context;
    const EVP_MD* md;
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLength;

    md = EVP_get_digestbyname("sha256");
    context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, md, nullptr);
    EVP_DigestUpdate(context, ss.str().c_str(), ss.str().length());
    EVP_DigestFinal_ex(context, hash, &hashLength);

    stringstream hashStream;
    for (unsigned int i = 0; i < hashLength; ++i) {
        hashStream << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }

    return hashStream.str();
}

void Block::mineBlock(int difficulty) {
    string target(difficulty, '0');

    for (int _nonce = 0; _nonce <= INT_MAX; _nonce++) {
        this->nonce = to_string(_nonce);

        string _hash = calculateHash();

        if (_hash.substr(0, difficulty) == target) {
            this->hash = _hash;
            return;
        }
    }

    throw runtime_error("Nonce not found");
}



#endif //BLOCKCHIAN_BLOCK_H
