
#ifndef _shower_factory_h_
#define _shower_factory_h_

#include <JANA/JFactoryT.h>

#include "shower.h"

class ShowerFactory : public JFactoryT<Shower> {
public:
    ShowerFactory() : JFactoryT<Shower>(NAME_OF_THIS) {};
    void Init() override;
    void ChangeRun(const std::shared_ptr<const JEvent> &aEvent) override;
    void Process(const std::shared_ptr<const JEvent> &aEvent) override;

};

#endif // _shower_factory_h_