/*
 *
 * AccessibleComponent function implementations
 *
 */

#include <cspi/spi-private.h>

/**
 * AccessibleComponent_ref:
 * @obj: a pointer to an object implementing #AccessibleComponent on which to operate.
 *
 * Increment the reference count for an #AccessibleComponent.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
AccessibleComponent_ref (AccessibleComponent *obj)
{
  Accessibility_Component_ref (*obj, spi_ev ());
  return 0;
}

/**
 * AccessibleComponent_unref:
 * @obj: a pointer to the object implementing #AccessibleComponent on which to operate.
 *
 * Decrement the reference count for an #AccessibleComponent.
 *
 * Returns: (no return code implemented yet).
 *
 **/
int
AccessibleComponent_unref (AccessibleComponent *obj)
{
  Accessibility_Component_unref (*obj, spi_ev ());
  return 0;
}

/**
 * AccessibleComponent_contains:
 * @obj: a pointer to the #AccessibleComponent to query.
 * @x: a #long specifying the x coordinate in question.
 * @y: a #long specifying the y coordinate in question.
 * @ctype: the desired coordinate system of the point (@x, @y)
 *         (e.g. SPI_COORD_TYPE_WINDOW, SPI_COORD_TYPE_SCREEN).
 *
 * Query whether a given #AccessibleComponent contains a particular point.
 *
 * Returns: a #TRUE if the specified component contains the point (@x, @y),
 *          otherwise #FALSE.
 **/
boolean
AccessibleComponent_contains (AccessibleComponent *obj,
                              long int x,
                              long int y,
                              AccessibleCoordType ctype)
{
  return Accessibility_Component_contains (*obj,
                                           (CORBA_long) x,
                                           (CORBA_long) y,
                                           ctype,
                                           spi_ev ());
}

/**
 * AccessibleComponent_getAccessibleAtPoint:
 * @obj: a pointer to the #AccessibleComponent to query.
 * @x: a #long specifying the x coordinate of the point in question.
 * @y: a #long specifying the y coordinate of the point in question.
 * @ctype: the coordinate system of the point (@x, @y)
 *         (e.g. SPI_COORD_TYPE_WINDOW, SPI_COORD_TYPE_SCREEN).
 *
 * Get the accessible child at a given coordinate within an #AccessibleComponent.
 *
 * Returns: a pointer to an #Accessible child of the specified component which
 *          contains the point (@x, @y), or NULL of no child contains the point.
 **/
Accessible *
AccessibleComponent_getAccessibleAtPoint (AccessibleComponent *obj,
                                          long int x,
                                          long int y,
                                          AccessibleCoordType ctype)
{
  Accessible child;
  child = Accessibility_Component_getAccessibleAtPoint(*obj,
                                                       (CORBA_long) x,
                                                       (CORBA_long) y,
                                                       ctype,
                                                       spi_ev ());
  return spi_object_add (child);
}

/**
 * AccessibleComponent_getExtents:
 * @obj: a pointer to the #AccessibleComponent to query.
 * @x: a pointer to a #long into which the minimum x coordinate will be returned.
 * @y: a pointer to a #long into which the minimum y coordinate will be returned.
 * @width: a pointer to a #long into which the x extents (width) will be returned.
 * @height: a pointer to a #long into which the y extents (height) will be returned.
 * @ctype: the desired coordinate system into which to return the results,
 *         (e.g. SPI_COORD_TYPE_WINDOW, SPI_COORD_TYPE_SCREEN).
 *
 * Get the bounding box of the specified #AccessibleComponent.
 *
 **/
void
AccessibleComponent_getExtents (AccessibleComponent *obj,
                                long int *x,
                                long int *y,
                                long int *width,
                                long int *height,
                                AccessibleCoordType ctype)
{
  CORBA_long cx, cy, cw, ch;	
  Accessibility_Component_getExtents (*obj,
                                      &cx,
                                      &cy,
                                      &cw,
                                      &ch,
				      ctype,
				      spi_ev ());
  spi_warn_ev (spi_ev (), "AccessibleComponent_getExtents");
  *x = (long) cx;
  *y = (long) cy;
  *width = (long) cw;
  *height = (long) ch;
}

/**
 * AccessibleComponent_getPosition:
 * @obj: a pointer to the #AccessibleComponent to query.
 * @x: a pointer to a #long into which the minimum x coordinate will be returned.
 * @y: a pointer to a #long into which the minimum y coordinate will be returned.
 * @ctype: the desired coordinate system into which to return the results,
 *         (e.g. SPI_COORD_TYPE_WINDOW, SPI_COORD_TYPE_SCREEN).
 *
 * Get the minimum x and y coordinates of the specified #AccessibleComponent.
 *
 **/
void
AccessibleComponent_getPosition (AccessibleComponent *obj,
                                 long int *x,
                                 long int *y,
                                 AccessibleCoordType ctype)
{
  Accessibility_Component_getPosition (*obj,
                                       (CORBA_long *) x,
                                       (CORBA_long *) y,
                                       ctype,
                                       spi_ev ());
}

/**
 * AccessibleComponent_getSize:
 * @obj: a pointer to the #AccessibleComponent to query.
 * @width: a pointer to a #long into which the x extents (width) will be returned.
 * @height: a pointer to a #long into which the y extents (height) will be returned.
 *
 * Get the size of the specified #AccessibleComponent.
 *
 **/
void
AccessibleComponent_getSize (AccessibleComponent *obj,
                             long int *width,
                             long int *height)
{
  Accessibility_Component_getSize (*obj,
                                   (CORBA_long *) width,
                                   (CORBA_long *) height,
                                   spi_ev ());
}

/**
 * AccessibleComponent_grabFocus:
 * @obj: a pointer to the #AccessibleComponent on which to operate.
 *
 * Attempt to set the keyboard input focus to the specified
 *         #AccessibleComponent.
 *
 **/
void
AccessibleComponent_grabFocus (AccessibleComponent *obj)
{
  ;
}
