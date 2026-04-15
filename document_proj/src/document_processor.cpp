#include "document_processor.hpp"

void DocumentProcessor::processAll(
    std::vector<std::unique_ptr<Document>> docsVec)
{
    _docsData.clear();

    for(size_t idx = 0; idx < docsVec.size(); ++idx)
    {
        auto& document = docsVec[idx];
        document->open();
        DocInfo currDocInfo{document->getFormatName(),
                            document->extractContent(),
                            document->getWordCount()};

        // Docs vector will be destroyed here!
        _docsData[idx] =
            std::make_pair(std::move(document), std::move(currDocInfo));
    }
}

void DocumentProcessor::updateAll(void)
{
    for(auto& [docIdx, docPair]: _docsData)
    {
        std::unique_ptr<Document>& document = docPair.first;
        DocInfo newInfo{document->getFormatName(), document->extractContent(),
                        document->getWordCount()};

        docPair.second = std::move(newInfo);
    }
}

void DocumentProcessor::exportAll(std::ostream& streamToExport)
{
    for(auto& [docIdx, pairInfo]: _docsData)
    {
        const DocInfo& docInfo = pairInfo.second;

        streamToExport << "Document index: " << docIdx
                       << "\n\tformat name: " << docInfo.formatName
                       << "\n\twords count: " << docInfo.wordsCnt
                       << "\n\tContent: " << docInfo.content << "\n";
    }
}
