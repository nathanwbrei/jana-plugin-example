#ifndef _stdout_processor_h_
#define _stdout_processor_h_

#include <JANA/JEventProcessor.h>

class StdoutProcessor : public JEventProcessor {
public:

    StdoutProcessor();
    virtual ~StdoutProcessor() = default;

    void Init() override;
    void Process(const std::shared_ptr<const JEvent>& event) override;
    void Finish() override;

};


#endif // _stdout_processor_h_
