// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  WellBoreScriptingPluginInfo.C
// ************************************************************************* //
#include <PyWellBoreAttributes.h>
#include <WellBorePluginInfo.h>

VISIT_PLOT_PLUGIN_ENTRY(WellBore,Scripting)

// ****************************************************************************
// Method: WellBoreScriptingPluginInfo::InitializePlugin
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
WellBoreScriptingPluginInfo::InitializePlugin(AttributeSubject *subj,
    void *data)
{
    PyWellBoreAttributes_StartUp((WellBoreAttributes *)subj, data);
}

// ****************************************************************************
// Method: WellBoreScriptingPluginInfo::GetMethodTable
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
WellBoreScriptingPluginInfo::GetMethodTable(int *nMethods)
{
    return PyWellBoreAttributes_GetMethodTable(nMethods);
}

// ****************************************************************************
// Method: WellBoreScriptingPluginInfo::TypesMatch
//
// Purpose:
//   Returns whether or not the input PyObject is WellBore plot attributes.
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
WellBoreScriptingPluginInfo::TypesMatch(void *pyobject)
{
    return PyWellBoreAttributes_Check((PyObject *)pyobject);
}

// ****************************************************************************
// Method: WellBoreScriptingPluginInfo::GetLogString
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
WellBoreScriptingPluginInfo::GetLogString()
{
    std::string s(PyWellBoreAttributes_GetLogString());
    char *v = new char[s.size() + 1];
    strcpy(v, s.c_str());
    return v;
}

// ****************************************************************************
// Method: WellBoreScriptingPluginInfo::SetDefaults
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
WellBoreScriptingPluginInfo::SetDefaults(const AttributeSubject *atts)
{
    PyWellBoreAttributes_SetDefaults((const WellBoreAttributes *)atts);
}
