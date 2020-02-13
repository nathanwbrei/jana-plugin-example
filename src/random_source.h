
#ifndef _random_source_h_
#define  _random_source_h_

#include <JANA/JEventSource.h>
#include <random>

/// RandomSource will emit hit data which gets generated randomly on the fly
/// This is useful for testing the downstream components without requiring real input data
class RandomSource : public JEventSource {
private:
    int m_seed;
    std::mt19937* m_generator;

public:
    RandomSource(JApplication* app);

    virtual ~RandomSource() = default;

    void Open() override;

    void GetEvent(std::shared_ptr<JEvent>) override;

};


#endif