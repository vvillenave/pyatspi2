#include <stdlib.h> /* for malloc */
#include <cspi/spi-private.h>

#define MAX_ROLES 100

static char *role_names [MAX_ROLES] =
{
  " ",
  "accelerator label",
  "alert",
  "animation",
  "arrow",
  "calendar",
  "canvas",
  "check box",
  "menu item",
  "color chooser",
  "column header",
  "combo box",
  "date editor",
  "desktop icon",
  "desktop frame",
  "dial",
  "dialog",
  "directory pane",
  "drawing area",
  "file chooser",
  "filler",
  "font chooser",
  "frame",
  "glass pane",
  "HTML container",
  "icon",
  "image",
  "internal frame",
  "label",
  "layered pane",
  "list",
  "list item",
  "menu",
  "menubar",
  "menu item",
  "option pane",
  "page tab",
  "page tab list",
  "panel",
  "password text",
  "popup menu",
  "progress bar",
  "pushbutton",
  "radiobutton",
  "radio menu item",
  "root pane",
  "row header",
  "scrollbar",
  "scrollpane",
  "separator",
  "slider",
  "split pane",
  "spin button",
  "status bar",
  "table",
  "table cell",
  "table column header",
  "table row header",
  "tearoff menu item",
  "text",
  "toggle button",
  "toolbar",
  "tooltip",
  "tree",
  " ",
  "viewport",
  "window",
};

/**
 * AccessibleRole_getName:
 * @role: an #AccessibleRole object to query.
 *
 * Get a localizeable string that indicates the name of an #AccessibleRole.
 *
 * Returns: a localizable string name for an #AccessibleRole enumerated type.
 **/
char*
AccessibleRole_getName (AccessibleRole role)
{
  if (role < MAX_ROLES) return role_names [(int) role];
  else return "";
}



/**
 * Accessible_ref:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Increment the reference count for an #Accessible object.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
Accessible_ref (Accessible *obj)
{
  Accessibility_Accessible_ref (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "ref");
  return 0;
}


/**
 * Accessible_unref:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Decrement the reference count for an #Accessible object.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
Accessible_unref (Accessible *obj)
{
  Accessibility_Accessible_unref (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "unref");
  return 0;
}

/**
 * Accessible_getName:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Get the name of an #Accessible object.
 *
 * Returns: a UTF-8 string indicating the name of the #Accessible object.
 *
 **/
char *
Accessible_getName (Accessible *obj)
{
  char *retval = 
    (char *)
    Accessibility_Accessible__get_name (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "getName"); 
  return retval;
}

/**
 * Accessible_getDescription:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Get the description of an #Accessible object.
 *
 * Returns: a UTF-8 string describing the #Accessible object.
 *
 **/
char *
Accessible_getDescription (Accessible *obj)
{
  char *retval = (char *)
    Accessibility_Accessible__get_description (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "getDescription");
  return retval;
}

/**
 * Accessible_getParent:
 * @obj: a pointer to the #Accessible object to query.
 *
 * Get an #Accessible object's parent container.
 *
 * Returns: a pointer tothe #Accessible object which contains the given
 *          #Accessible instance, or NULL if the @obj has no parent container.
 *
 **/
Accessible *
Accessible_getParent (Accessible *obj)
{
  Accessible *retval = 
      spi_object_add (Accessibility_Accessible__get_parent (*obj, spi_ev ()));
  spi_check_ev (spi_ev (), "getParent");
  return retval;
}

/**
 * Accessible_getChildCount:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Get the number of children contained by an #Accessible object.
 *
 * Returns: a #long indicating the number of #Accessible children
 *          contained by an #Accessible object.
 *
 **/
long
Accessible_getChildCount (Accessible *obj)
{
  long retval = (long) Accessibility_Accessible__get_childCount (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "getChildCount");
  return retval;
}

/**
 * Accessible_getChildAtIndex:
 * @obj: a pointer to the #Accessible object on which to operate.
 * @childIndex: a #long indicating which child is specified.
 *
 * Get the #Accessible child of an #Accessible object at a given index.
 *
 * Returns: a pointer to the #Accessible child object at index
 *          @childIndex.
 *
 **/
Accessible *
Accessible_getChildAtIndex (Accessible *obj,
                            long int childIndex)
{
  Accessible *retval = spi_object_add (Accessibility_Accessible_getChildAtIndex (*obj, childIndex, spi_ev ()));
  spi_check_ev (spi_ev (), "getChildAtIndex");
  return retval;
}

/**
 * Accessible_getIndexInParent:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Get the index of an #Accessible object in its containing #Accessible.
 *
 * Returns: a #long indicating the index of the #Accessible object
 *          in its parent (i.e. containing) #Accessible instance,
 *          or -1 if @obj has no containing parent.
 *
 **/
long
Accessible_getIndexInParent (Accessible *obj)
{
  long retval = (long) Accessibility_Accessible_getIndexInParent (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "getIndexInParent");
  return retval;
}

/**
 * Accessible_getRelationSet:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Get the set of #AccessibleRelation objects which describe this #Accessible object's
 *       relationships with other #Accessible objects.
 *
 * Returns: an array of #AccessibleRelation pointers.
 *
 **/
AccessibleRelation **
Accessible_getRelationSet (Accessible *obj)
{
  AccessibleRelation **relations;
  int n_relations;
  int i;
  Accessibility_RelationSet *relation_set =	
	  Accessibility_Accessible_getRelationSet (*obj, spi_ev ());
  
  /* this looks hack-ish, but it's based on the CORBA C bindings spec */
  n_relations = relation_set->_length;
  relations = malloc (sizeof (AccessibleRelation *) * n_relations);
  
  for (i=0; i<n_relations; ++i)
    {
      relations[i] = spi_object_add (relation_set->_buffer[i]);
    }
  relations[i] = CORBA_OBJECT_NIL;

  return relations;
}

/**
 * Accessible_getRole:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Get the UI role of an #Accessible object.
 *
 * Returns: a UTF-8 string indicating the UI role of the #Accessible object.
 *
 **/
char *
Accessible_getRole (Accessible *obj)
{
  char *retval = AccessibleRole_getName (
		  Accessibility_Accessible_getRole (*obj, spi_ev ()));
  spi_check_ev (spi_ev (), "getRole");
  return retval;
}

/**
 * Accessible_getStateSet:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Not Yet Implemented.
 *
 * Returns: a pointer to an #AccessibleStateSet representing the object's current state.
 **/
AccessibleStateSet *
Accessible_getStateSet (Accessible *obj)
{
  return NULL;
}

/* Interface query methods */

/**
 * Accessible_isAction:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleAction.
 *
 * Returns: #TRUE if @obj implements the #AccessibleAction interface,
 *          #FALSE otherwise.
 **/
boolean
Accessible_isAction (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Action:1.0",
                                             spi_ev ());
  spi_warn_ev (spi_ev (), "isAction");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_isComponent:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleComponent.
 *
 * Returns: #TRUE if @obj implements the #AccessibleComponent interface,
 *          #FALSE otherwise.
 **/
boolean
Accessible_isComponent (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Component:1.0",
                                             spi_ev ());
  spi_warn_ev (spi_ev (), "isComponent");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_isEditableText:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleEditableText.
 *
 * Returns: #TRUE if @obj implements the #AccessibleEditableText interface,
 *          #FALSE otherwise.
 **/
boolean
Accessible_isEditableText (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/EditableText:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "isEditableText");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_isHypertext:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleHypertext.
 *
 * Returns: #TRUE if @obj implements the #AccessibleHypertext interface,
 *          #FALSE otherwise.
 **/
boolean
Accessible_isHypertext (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Hypertext:1.0",
                                             spi_ev ());

  spi_check_ev (spi_ev (), "isHypertext");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_isImage:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleImage.
 *
 * Returns: #TRUE if @obj implements the #AccessibleImage interface,
 *          #FALSE otherwise.
**/
boolean
Accessible_isImage (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Image:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "isImage");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_isSelection:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleSelection.
 *
 * Returns: #TRUE if @obj implements the #AccessibleSelection interface,
 *          #FALSE otherwise.
**/
boolean
Accessible_isSelection (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Selection:1.0",
                                             spi_ev ());
  spi_warn_ev (spi_ev (), "isSelection");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;

}

/**
 * Accessible_isTable:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleTable.
 *
 * Returns: #TRUE if @obj implements the #AccessibleTable interface,
 *          #FALSE otherwise.
**/
boolean
Accessible_isTable (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Table:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "isTable");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;

}

/**
 * Accessible_isText:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleText.
 *
 * Returns: #TRUE if @obj implements the #AccessibleText interface,
 *          #FALSE otherwise.
**/
boolean
Accessible_isText (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Text:1.0",
                                             spi_ev ());
  spi_warn_ev (spi_ev (), "isText");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_isValue:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Query whether the specified #Accessible implements #AccessibleValue.
 *
 * Returns: #TRUE if @obj implements the #AccessibleValue interface,
 *          #FALSE otherwise.
**/
boolean
Accessible_isValue (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Value:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "isValue");

  return (CORBA_Object_is_nil (iface, spi_ev ())) ? FALSE : TRUE;
}

/**
 * Accessible_getAction:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleAction interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleAction interface instance, or
 *          NULL if @obj does not implement #AccessibleAction.
 **/
AccessibleAction *
Accessible_getAction (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Action:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "getAction");

  return (AccessibleAction *) spi_object_add (iface);
}

/**
 * Accessible_getComponent:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleComponent interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleComponent interface instance, or
 *          NULL if @obj does not implement #AccessibleComponent.
 **/
AccessibleComponent *
Accessible_getComponent (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Component:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "getComponent");

  return (AccessibleComponent *) spi_object_add (iface);
}

/**
 * Accessible_getEditableText:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleEditableText interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleEditableText interface instance, or
 *          NULL if @obj does not implement #AccessibleEditableText.
 **/
AccessibleEditableText *
Accessible_getEditableText (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/EditableText:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "getEditableText");

  return (AccessibleEditableText *) spi_object_add (iface);
}



/**
 * Accessible_getHypertext:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleHypertext interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleHypertext interface instance, or
 *          NULL if @obj does not implement #AccessibleHypertext.
 **/
AccessibleHypertext *
Accessible_getHypertext (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Hypertext:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "getHypertext");

  return (AccessibleHypertext *) spi_object_add (iface);
}



/**
 * Accessible_getImage:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleImage interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleImage interface instance, or
 *          NULL if @obj does not implement #AccessibleImage.
 **/
AccessibleImage *
Accessible_getImage (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Image:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "getImage");

  return (AccessibleImage *) spi_object_add (iface);
}



/**
 * Accessible_getSelection:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleSelection interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleSelection interface instance, or
 *          NULL if @obj does not implement #AccessibleSelection.
 **/
AccessibleSelection *
Accessible_getSelection (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Selection:1.0",
                                             spi_ev ());
  spi_warn_ev (spi_ev (), "getSelection");

  return (AccessibleSelection *) spi_object_add (iface);
}



/**
 * Accessible_getTable:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleTable interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleTable interface instance, or
 *          NULL if @obj does not implement #AccessibleTable.
 **/
AccessibleTable *
Accessible_getTable (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Table:1.0",
                                             spi_ev ());
  spi_check_ev (spi_ev (), "getTable");

  return (AccessibleTable *) spi_object_add (iface);
}

/**
 * Accessible_getText:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleText interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleText interface instance, or
 *          NULL if @obj does not implement #AccessibleText.
 **/
AccessibleText *
Accessible_getText (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Text:1.0",
                                             spi_ev ());

  spi_check_ev (spi_ev (), "getText"); 

  return (AccessibleText *) spi_object_add (iface);
}



/**
 * Accessible_getValue:
 * @obj: a pointer to the #Accessible instance to query.
 *
 * Get the #AccessibleValue interface for an #Accessible.
 *
 * Returns: a pointer to an #AccessibleValue interface instance, or
 *          NULL if @obj does not implement #AccessibleValue.
 **/
AccessibleValue *
Accessible_getValue (Accessible *obj)
{
  Bonobo_Unknown iface =
    Accessibility_Accessible_queryInterface (*obj,
                                             "IDL:Accessibility/Value:1.0",
                                             spi_ev ());
  return (AccessibleValue *) spi_object_add (iface);
}



/**
 * Accessible_queryInterface:
 * @obj: a pointer to the #Accessible instance to query.
 * @interface_name: a UTF-8 character string specifiying the requested interface.
 *
 * Query an #Accessible object to for a named interface.
 *
 * Returns: an instance of the named interface object, if it is implemented
 *          by @obj, or NULL otherwise.
 *
 **/
GenericInterface *
Accessible_queryInterface (Accessible *obj, char *interface_name)
{
  GenericInterface iface;
  iface = Accessibility_Accessible_queryInterface (*obj,
                                                    interface_name,
                                                    spi_ev ());
  return spi_object_add (iface);
}


/**
 * AccessibleRelation_ref:
 * @obj: a pointer to the #AccessibleRelation object on which to operate.
 *
 * Increment the reference count for an #AccessibleRelation object.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
AccessibleRelation_ref (AccessibleRelation *obj)
{
  Accessibility_Relation_ref (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "ref");
  return 0;
}

/**
 * AccessibleRelation_unref:
 * @obj: a pointer to the #AccessibleRelation object on which to operate.
 *
 * Decrement the reference count for an #AccessibleRelation object.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
AccessibleRelation_unref (AccessibleRelation *obj)
{
  Accessibility_Relation_unref (*obj, spi_ev ());
  spi_check_ev (spi_ev (), "unref");
  return 0;
}

/**
 * AccessibleRelation_getRelationType:
 * @obj: a pointer to the #AccessibleRelation object to query.
 *
 * Get the type of relationship represented by an #AccessibleRelation.
 *
 * Returns: an #AccessibleRelationType indicating the type of relation
 *         encapsulated in this #AccessibleRelation object.
 *
 **/
AccessibleRelationType
AccessibleRelation_getRelationType (AccessibleRelation *obj)
{
  return 0;
}

/**
 * AccessibleRelation_getNTargets:
 * @obj: a pointer to the #AccessibleRelation object to query.
 *
 * Get the number of objects which this relationship has as its
 *       target objects (the subject is the #Accessible from which this
 *       #AccessibleRelation originated).
 *
 * Returns: a short integer indicating how many target objects which the
 *       originating #Accessible object has the #AccessibleRelation
 *       relationship with.
 **/
int
AccessibleRelation_getNTargets (AccessibleRelation *obj)
{
  return 0;
}

/**
 * AccessibleRelation_getTarget:
 * @obj: a pointer to the #AccessibleRelation object to query.
 * @i: a (zero-index) integer indicating which (of possibly several) target is requested.
 *
 * Get the @i-th target of a specified #AccessibleRelation relationship.
 *
 * Returns: an #Accessible which is the @i-th object with which the
 *      originating #Accessible has relationship specified in the
 *      #AccessibleRelation object.
 *
 **/
Accessible *
AccessibleRelation_getTarget (AccessibleRelation *obj, int i)
{
  return NULL;
}

/**
 * AccessibleStateSet_ref:
 * @obj: a pointer to the #AccessibleStateSet object on which to operate.
 *
 * Increment the reference count for an #AccessibleStateSet object.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
AccessibleStateSet_ref (AccessibleStateSet *obj)
{
/*  Accessibility_StateSet_ref (*obj, spi_ev ()); */
  spi_check_ev (spi_ev (), "ref");
  return 0;
}

/**
 * AccessibleStateSet_unref:
 * @obj: a pointer to the #AccessibleStateSet object on which to operate.
 *
 * Decrement the reference count for an #AccessibleStateSet object.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
AccessibleStateSet_unref (AccessibleStateSet *obj)
{
/*  Accessibility_StateSet_unref (*obj, spi_ev ()); */
  spi_check_ev (spi_ev (), "unref");
  return 0;
}


/**
 * AccessibleStateSet_contains:
 * @obj: a pointer to the #AccessibleStateSet object on which to operate.
 * @state: an #AccessibleState for which the specified #AccessibleStateSet
 *       will be queried.
 *
 * Determine whether a given #AccessibleStateSet includes a given state; that is,
 *       whether @state is true for the stateset in question.
 *
 * Returns: #TRUE if @state is true/included in the given #AccessibleStateSet,
 *          otherwise #FALSE.
 *
 **/
boolean
AccessibleStateSet_contains (AccessibleStateSet *obj,
			     AccessibleState state)
{
  CORBA_boolean retval = Accessibility_StateSet_contains (*obj, state, spi_ev ());
  spi_check_ev (spi_ev (), "contains");
  return (boolean) retval;
}

/**
 * AccessibleStateSet_add:
 * @obj: a pointer to the #AccessibleStateSet object on which to operate.
 * @state: an #AccessibleState to be added to the specified #AccessibleStateSet
 *
 * Add a particular #AccessibleState to an #AccessibleStateSet (i.e. set the
 *       given state to #TRUE in the stateset.
 *
 **/
void
AccessibleStateSet_add (AccessibleStateSet *obj,
			AccessibleState state)
{
  Accessibility_StateSet_add (*obj, state, spi_ev ());
  spi_check_ev (spi_ev (), "contains");
}


/**
 * AccessibleStateSet_remove:
 * @obj: a pointer to the #AccessibleStateSet object on which to operate.
 * @state: an #AccessibleState to be removed from the specified #AccessibleStateSet
 *
 * Remove a particular #AccessibleState to an #AccessibleStateSet (i.e. set the
 *       given state to #FALSE in the stateset.)
 *
 **/
void
AccessibleStateSet_remove (AccessibleStateSet *obj,
			   AccessibleState state)
{
  Accessibility_StateSet_remove (*obj, state, spi_ev ());
  spi_check_ev (spi_ev (), "contains");
}

/**
 * AccessibleStateSet_equals:
 * @obj: a pointer to the first #AccessibleStateSet object on which to operate.
 * @obj2: a pointer to the second #AccessibleStateSet object on which to operate.
 *
 * Determine whether two instances of #AccessibleStateSet are equivalent (i.e.
 *         consist of the same #AccessibleStates).  Useful for checking multiple
 *         state variables at once; construct the target state then compare against it.
 *
 * @see AccessibleStateSet_compare().
 *
 * Returns: #TRUE if the two #AccessibleStateSets are equivalent,
 *          otherwise #FALSE.
 *
 **/
boolean
AccessibleStateSet_equals (AccessibleStateSet *obj,
                           AccessibleStateSet *obj2)
{
  return Accessibility_StateSet_equals (*obj, *obj2, spi_ev ());
}

/**
 * AccessibleStateSet_compare:
 * @obj: a pointer to the first #AccessibleStateSet object on which to operate.
 * @obj2: a pointer to the second #AccessibleStateSet object on which to operate.
 * @differenceSet: a pointer to an array of #AccessibleStates, which is set when the
 *        fuction returns to point to an array of states representing the states which
 *        the two state sets do not have in common.
 *
 * Determine the differences between two instances of #AccessibleStateSet.
 *.
 * @see AccessibleStateSet_equals().
 *
 * Returns: an #AccessibleStateSet object containing all states contained on one of
 *          the two sets but not the other.
 *
 **/
void
AccessibleStateSet_compare (AccessibleStateSet *obj,
                            AccessibleStateSet *obj2,
                            AccessibleStateSet **differenceSet);


/**
 * AccessibleStateSet_isEmpty:
 * @obj: a pointer to the #AccessibleStateSet object on which to operate.
 *
 * Determine whether a given #AccessibleStateSet is the empty set.
 *
 * Returns: #TRUE if the given #AccessibleStateSet contains no (true) states,
 *          otherwise #FALSE.
 *
 **/
boolean
AccessibleStateSet_isEmpty (AccessibleStateSet *obj)
{
  return TRUE;	
  /*  return Accessibility_StateSet_isEmpty (*obj, spi_ev ());*/
}




