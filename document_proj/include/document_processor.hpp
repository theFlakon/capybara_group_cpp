#ifndef DOCUMENT_PROCESSOR_HPP
#define DOCUMENT_PROCESSOR_HPP

#include "document.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <vector>

struct DocInfo
{
    std::string formatName{};
    std::string content{};
    size_t wordsCnt{};

    DocInfo(std::string format, std::string cont, size_t wordsCount)
        : formatName(std::move(format)), content(std::move(cont)),
          wordsCnt(wordsCount)
    {
    }

    DocInfo() = default;
};

class DocumentProcessor
{
private:
    // 'doc_idx' : {document, DocInfo}
    std::map<size_t, std::pair<std::unique_ptr<Document>, DocInfo>> _docsData{};

public:
    // !!! It will destroy docsVec
    void processAll(std::vector<std::unique_ptr<Document>> docsVec);

    void updateAll(void);
    void exportAll(std::ostream& streamToExport);
};

#endif
