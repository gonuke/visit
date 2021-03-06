// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  HistogramScriptingPluginInfo.C
// ************************************************************************* //
#include <PyHistogramAttributes.h>
#include <HistogramPluginInfo.h>

VISIT_PLOT_PLUGIN_ENTRY(Histogram,Scripting)

// ****************************************************************************
// Method: HistogramScriptingPluginInfo::InitializePlugin
//
// Purpose:
//   Calls the initialization function for the plugin.
//
// Arguments:
//   subj    : A pointer to the plugin's state object.
//   data    : A pointer to data to be used by the observer function.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
HistogramScriptingPluginInfo::InitializePlugin(AttributeSubject *subj,
    void *data)
{
    PyHistogramAttributes_StartUp((HistogramAttributes *)subj, data);
}

// ****************************************************************************
// Method: HistogramScriptingPluginInfo::GetMethodTable
//
// Purpose:
//   Returns a pointer to the plugin's Python method table. These methods are
//   added to the top-level visit module's methods.
//
// Arguments:
//   nMethods : Returns the number of methods in the method table.
//
// Returns:    A pointer to the method table.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void *
HistogramScriptingPluginInfo::GetMethodTable(int *nMethods)
{
    return PyHistogramAttributes_GetMethodTable(nMethods);
}

// ****************************************************************************
// Method: HistogramScriptingPluginInfo::TypesMatch
//
// Purpose:
//   Returns whether or not the input PyObject is Histogram plot attributes.
//
// Arguments:
//   pyobject : A PyObject cast to void*.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
HistogramScriptingPluginInfo::TypesMatch(void *pyobject)
{
    return PyHistogramAttributes_Check((PyObject *)pyobject);
}

// ****************************************************************************
// Method: HistogramScriptingPluginInfo::GetLogString
//
// Purpose:
//   Gets a string representation of the current attributes.
//
// Arguments:
//   val : Whether or not to log state information.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

char *
HistogramScriptingPluginInfo::GetLogString()
{
    std::string s(PyHistogramAttributes_GetLogString());
    char *v = new char[s.size() + 1];
    strcpy(v, s.c_str());
    return v;
}

// ****************************************************************************
// Method: HistogramScriptingPluginInfo::SetDefaults
//
// Purpose:
//   Used to set the default values for a plugin's state object.
//
// Arguments:
//   atts : The new state.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
HistogramScriptingPluginInfo::SetDefaults(const AttributeSubject *atts)
{
    PyHistogramAttributes_SetDefaults((const HistogramAttributes *)atts);
}
