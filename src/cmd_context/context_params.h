/*++
Copyright (c) 2011 Microsoft Corporation

Module Name:

    context_params.h

Abstract:

    Goodies for managing context parameters in the cmd_context and
    api_context

Author:

    Leonardo (leonardo) 2012-12-01

Notes:

--*/
#ifndef _CONTEXT_PARAMS_H_
#define _CONTEXT_PARAMS_H_

#include"params.h"
class ast_manager;

class context_params {
    void set_bool(bool & opt, char const * param, char const * value);
        
public:
    bool        m_auto_config;
    bool        m_proof;
    bool        m_interpolants;
    bool        m_check_interpolants;
    bool        m_debug_ref_count;
    bool        m_trace;
    std::string m_trace_file_name;
    bool        m_well_sorted_check;
    bool        m_model;
    bool        m_model_validate;
    bool        m_unsat_core;
    bool        m_smtlib2_compliant; // it must be here because it enable/disable the use of coercions in the ast_manager.
    unsigned    m_timeout;

    context_params();
    void set(char const * param, char const * value);
    void updt_params();
    void updt_params(params_ref const & p);
    static void collect_param_descrs(param_descrs & d);
    /*
      REG_PARAMS('context_params::collect_param_descrs')
    */
    
    /**
       \brief Goodies for extracting parameters for creating a solver object.
    */
    void get_solver_params(ast_manager const & m, params_ref & p, bool & proofs_enabled, bool & models_enabled, bool & unsat_core_enabled);

    /**
       \brief Include in p parameters derived from this context_params.
       These are parameters that are meaningful for tactics and solvers.
       Example: auto_config
    */
    params_ref merge_default_params(params_ref const & p);
    
    /**
       \brief Create an AST manager using this configuration.
    */
    ast_manager * mk_ast_manager();
};


#endif
