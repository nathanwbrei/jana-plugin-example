
How do I create a new project?
We provide a script for generating a project skeleton! 
jana-skeleton project my_project_name
If you already have a project, but want to create a 'satellite' project which integrates with the original, see below.


How do I build?
1. Clone JANA via git (Prefer: submodule clone or external clone?)
2. Set JANA_HOME. Prefer: where exactly? Can we automatically get rid of this by using submodules?
3. Install JANA via cmake install
4. Install project via cmake


How do I run?
1. Put $JANA_HOME/bin on $PATH
2. jana -Pplugins=my_plugin path/to/my/data.evio


What belongs in a plugin?

The point of plugins is to be able to run different analyses in isolation from each other. This is particularly important if you have heavy dependencies such as ROOT, which incur runtime penalties or are difficult to build against on some systems. If you are working on an analysis which doesn't need to be run all the time, it should go in its own plugin. If the analysis is exploratory or otherwise not something you expect other people in the collaboration to use, you can maintain it in its own repository, as described later on. 
 

1. JEventProcessors which produce an output which your collaboration only wants some of the time, or perform an analysis which only you care about

2. JObjects, JFactories, JEventSources which are only used within that plugin

3. JObjects, JFactories, JEventSources which are used by multiple plugins belong in the 'common' static library instead.

4. For ergonomic purposes, it often makes sense to have a 'main' plugin for registering event processors that we always want to have run, e.g. for building DSTs.


How do I create a new plugin?

1. There is a script to make this easy!
- Create new directory under src/
- Add new directory to src/CMakeLists.txt
- Add new plugin_main.cc to src/plugin/
- Add new event_processor.cc,h to src/plugin
- Add new test cases for event_processor to tests/plugin
- Add new CMakeLists.txt 

Jana-skeleton plugin my_plugin_name 



How do I create a plugin which uses components from a project but lives on a different repository?

The basic idea is to import libcommon.a as an external target and compile a plugin to the same JANA_HOME. 

See 'satellite_skeleton'



What if I have dependencies on external libraries such as CCDB? (What about JANA itself?)
-- create a git submodule under 'external'
-- create a CMake external target e.g. 

How do I create a new JObject/JFactory/JEventProcessor?

Naming conventions:
Older project generally use the "JEventProcessor_MyProcName" convention. For new projects, another option is to use "my_proc_name_eventprocessor", e.g. "dst_eventprocessor" or "int_veto_digi_hit_mc_factory". If you are working within an existing project which adheres to a naming convention, always abide by it.

Components may belong to one particular plugin, or may be compiled into a common static library, if they are meant to be used by more than one plugin. 

Use the script! Jana-skeleton my_jobject_name my_plugin_name. => [src/my_plugin_name/my_jobject_name.cc

Testing: The script will automatically create empty unit tests for each component. You are encouraged to write 2 or 3 test cases verifying that your component does what you think it does in isolation from the rest of the system. You may find that this makes development a lot smoother. You can also think of your test cases as being a semi-formal specification 


When do I create a new module?

The purpose of modules is to put code which is likely to change at the same time in the same place. For example, it makes sense to put code corresponding to each detector in its own module. Modules aren't so important for small projects but make a big difference ergonomically when the project has more than a hundred source files.

You can automatically create a module via
jana-skeleton module my_module_name. 
and add components to your module via 
jana-skeleton eventsource --plugin my_plugin_name --module my_module_name --name my_eventsource_name 







