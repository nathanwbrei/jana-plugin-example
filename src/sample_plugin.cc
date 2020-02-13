

#include <JANA/JApplication.h>
#include <JANA/JFactoryGenerator.h>

#include "random_source.h"
#include "shower_factory.h"
#include "stdout_processor.h"

// This code is executed when the plugin is attached.
// It should always call InitJANAPlugin(app) first, and then do one or more of:
//   - Read configuration parameters
//   - Register JFactoryGenerators
//   - Register JEventProcessors
//   - Register JEventSourceGenerators (or JEventSources directly)
//   - Register JServices

extern "C" {
void InitPlugin(JApplication* app) {

    InitJANAPlugin(app);

    LOG << "Loading sample plugin" << LOG_END;

    // Create an event processor and register it directly with the JApplication.
    app->Add(new StdoutProcessor);

    // Register your factory(ies). Note that because JANA is responsible for creating multiple instances of these,
    // you pass JApplication a JFactoryGenerator which creates however many are needed. JANA provides a convenient
    // template which works if your factory has a zero-argument constructor. Otherwise, extend JFactoryGenerator manually.
    app->Add(new JFactoryGeneratorT<ShowerFactory>());

    // Create an event source and register it directly with the JApplication.
    // Note: If you to read one or more files which were passed as command line arguments, you should
    // wrap it in a JEventSourceGeneratorT instead. This will allow JANA to decide which JEventSource is best
    // suited for handling each particular file and instantiate JEventSources as needed.
    app->Add(new RandomSource("random", app));

}
}

