#ifndef CLI_READER_H
#define CLI_READER_H

#include <string>

// Apstraktna klasa Reader sluzi da apstrakuje ulazni tok koji se koristi. Svi tipovi citaca (readera)
// nasledjuju ovu klasu i imaju svoje implementacije nasledjenih metoda iz roditeljske klase.
class Reader {
public:
    explicit Reader(std::istream *in) : inputStream(in) {};

    virtual ~Reader() = default;

    // Cita jednu liniju sa zadatog ulaznog toka
    virtual std::string readNewLine() = 0;

    // Cita vise linija sa zadatog ulaznog toka sve dok ne naidje na EOF
    virtual std::string readMultiLine() = 0;
protected:
    static constexpr int MAX_LINE_SIZE = 512;
    std::string line;
    std::istream *inputStream;
};


#endif //CLI_READER_H