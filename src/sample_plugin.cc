

#include <JANA/JApplication.h>

/// This code is executed when the plugin is attached.
/// It should always call InitJANAPlugin(app) first, and then do one or more of:
///   - Read configuration parameters
///   - Register JFactoryGenerators
///   - Register JEventProcessors
///   - Register JEventSourceGenerators (or JEventSources directly)
///   - Register JServices

extern "C" {
void InitPlugin(JApplication* app) {

    InitJANAPlugin(app);
    LOG << "Loading sample plugin" << LOG_END;
}
}

