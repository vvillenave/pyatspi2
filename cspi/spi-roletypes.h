#ifndef _SPI_ROLETYPES_H_
#define _SPI_ROLETYPES_H_

#include <glib/gmacros.h>

G_BEGIN_DECLS

/**
 * AccessibleRole:
 * @SPI_ROLE_INVALID: role is not legal, something is wrong with this object
 * @SPI_ROLE_ALERT: Object is used to alert the user about something
 * @SPI_ROLE_CANVAS: Object that can be drawn into and is used to trap events
 * @SPI_ROLE_CHECK_BOX: Object representd a choice that can be checked or unchecked
 *                    and provides a separate indicator for the current state.
 * @SPI_ROLE_COLOR_CHOOSER: A specialized dialog that lets the user choose a color.
 * @SPI_ROLE_COLUMN_HEADER: The header for a column of data 
 * @SPI_ROLE_COMBO_BOX: A list of choices the user can select from
 * @SPI_ROLE_SPI_DESKTOP_ICON: An inconifed internal frame within a SPI_DESKTOP_PANE
 * @SPI_ROLE_SPI_DESKTOP_FRAME: A pane that supports internal frames and
 *              iconified versions of those internal frames.
 * @SPI_ROLE_DIALOG: A top level window with title bar and a border
 * @SPI_ROLE_DIRECTORY_PANE: A pane that allows the user to navigate
 *              through and select the contents of a directory.
 * @SPI_ROLE_FILE_CHOOSER: A specialized dialog that displays the files in the
 *               directory and lets the user select a file, browse a different
 *	 	 directory, or specify a filename.
 * @SPI_ROLE_FILLER: A object that fills up space in a user interface
 * @SPI_ROLE_FOCUS_TRAVERSABLE: XXX Not sure about this.
 * @SPI_ROLE_FRAME: A top level window with a title bar, border, menubar, etc.
 * @SPI_ROLE_GLASS_PANE: A pane that is guaranteed to be painted on top of all
 *               panes beneath it
 * @SPI_ROLE_HTML_CONTAINER: A document container for HTML, whose children
 *               represent the document content.
 * @SPI_ROLE_ICON: A small fixed size picture, typically used to decorate components.
 * @SPI_ROLE_INTERNAL_FRAME: A frame-like object that is clipped by a desktop pane.
 * @SPI_ROLE_LABEL: An object used to present an icon or short string in an interface
 * @SPI_ROLE_LAYERED_PANE: A specialized pane that allows its children to be drawn in layers
 *                         providing a  form of stacking order.
 * @SPI_ROLE_LIST: An object that presents a list of objects to the user and allows the
 *                         user to select one or more of them.
 * @SPI_ROLE_LIST_ITEM: An object that represents an element of a list.
 * @SPI_ROLE_MENU: An object usually found inside a menu bar that contains a list of
 *                 actions the user can choose from.
 * @SPI_ROLE_MENU_BAR: An object usually drawn at the top of the primary dialog box of an
 *                 application that contains a list of menus the user can choose from.
 * @SPI_ROLE_MENU_ITEM: An object usually contained in a menu that presents an
 *	           action the user can choose.
 * @SPI_ROLE_OPTION_PANE: A specialized pane whose primary use is inside a DIALOG 
 * @SPI_ROLE_PAGE_TAB: An object that is a child of a page tab list
 * @SPI_ROLE_PAGE_TAB_LIST: An object that presents a series of panels (or page tabs),
 *	  one at a time, through some mechanism provided by the object.
 * @SPI_ROLE_PANEL: A generic container that is often used to group objects.
 * @SPI_ROLE_PASSWORD_TEXT: A text object uses for passwords, or other places where
 *        the text content is not shown visibly to the user.
 * @SPI_ROLE_POPUP_MENU: A temporary window that is usually used to offer the user a
 *        list of choices, and then hides when the user selects one of those choices.
 * @SPI_ROLE_PROGRESS_BAR: An object used to indicate how much of a task has been completed.
 * @SPI_ROLE_PUSH_BUTTON: A specialized object which the user can interact with to tell
 *        the application to do something.
 * @SPI_ROLE_RADIO_BUTTON: A specialized check box that will cause other radio buttons in the
 *        same group to become uncghecked when this one is checked.
 * @SPI_ROLE_ROOT_PANE: A specialized pane that has a glass pane and a layered pane as its
 *        children.
 * @SPI_ROLE_ROW_HEADER: The header for a row of data
 * @SPI_ROLE_SCROLL_BAR: An object usually used to allow a user to incrementally
 *        view a large amount of data.
 * @SPI_ROLE_SCROLL_PANE: An object that allows a user to incrementally view a large amount
 *         of information.
 * @SPI_ROLE_SEPARATOR: An object usually contained in a menu to provide a visible and
 *        logical separation of the contents in a menu.
 * @SPI_ROLE_SLIDER: An object that allows the user to select from a bounded range.
 * @SPI_ROLE_SPLIT_PANE: A specialized panel that presents two other panels at the same time.
 * @SPI_ROLE_TABLE: An object used to rpesent information in terms of rows and columns.
 * @SPI_ROLE_TABLE_CELL: An object which is a descendant of a table,
 *        with a row/column location.  A cell may span multiple rows and columns.
 * @SPI_ROLE_TABLE_COLUMN_HEADER: An object which serves to describe a column in a table.
 * @SPI_ROLE_TABLE_ROW_HEADER: An object which serves to label or describe a row in a table.
 * @SPI_ROLE_TEXT: An object that presents text to the user
 * @SPI_ROLE_TOGGLE_BUTTON: A specialized push button that can be checked or unchecked,
 *	  but does not provide a separate indicator for the current state.
 * @SPI_ROLE_TOOL_BAR: A bar or palette usually composed of push buttons or toggle buttons
 * @SPI_ROLE_TOOL_TIP: An object that provides information about another object
 * @SPI_ROLE_TREE: An object used to repsent hierarchical information to the user.
 * @SPI_ROLE_UNKNOWN: The object contains some SpiAccessible information, but its role is
 *                    not known.
 * @SPI_ROLE_VIEWPORT: An object usually used in a scroll pane, which restricts the visual
 *                    area into which its contents are presented.
 * @SPI_ROLE_WINDOW: A top level window with no title or border.
 **/
typedef enum
{
  SPI_ROLE_INVALID,
  SPI_ROLE_ALERT,
  SPI_ROLE_CANVAS,
  SPI_ROLE_CHECK_BOX,
  SPI_ROLE_COLOR_CHOOSER,
  SPI_ROLE_COLUMN_HEADER,
  SPI_ROLE_COMBO_BOX,
  SPI_ROLE_SPI_DESKTOP_ICON,
  SPI_ROLE_SPI_DESKTOP_FRAME,
  SPI_ROLE_DIALOG,
  SPI_ROLE_DIRECTORY_PANE,
  SPI_ROLE_FILE_CHOOSER,
  SPI_ROLE_FILLER,
  SPI_ROLE_FOCUS_TRAVERSABLE,
  SPI_ROLE_FRAME,
  SPI_ROLE_GLASS_PANE,
  SPI_ROLE_HTML_CONTAINER,
  SPI_ROLE_ICON,
  SPI_ROLE_INTERNAL_FRAME,
  SPI_ROLE_LABEL,
  SPI_ROLE_LAYERED_PANE,
  SPI_ROLE_LIST,
  SPI_ROLE_LIST_ITEM,
  SPI_ROLE_MENU,
  SPI_ROLE_MENU_BAR,
  SPI_ROLE_MENU_ITEM,
  SPI_ROLE_OPTION_PANE,
  SPI_ROLE_PAGE_TAB,
  SPI_ROLE_PAGE_TAB_LIST,
  SPI_ROLE_PANEL,
  SPI_ROLE_PASSWORD_TEXT,
  SPI_ROLE_POPUP_MENU,
  SPI_ROLE_PROGRESS_BAR,
  SPI_ROLE_PUSH_BUTTON,
  SPI_ROLE_RADIO_BUTTON,
  SPI_ROLE_ROOT_PANE,
  SPI_ROLE_ROW_HEADER,
  SPI_ROLE_SCROLL_BAR,
  SPI_ROLE_SCROLL_PANE,
  SPI_ROLE_SEPARATOR,
  SPI_ROLE_SLIDER,
  SPI_ROLE_SPLIT_PANE,
  SPI_ROLE_TABLE,
  SPI_ROLE_TABLE_CELL,
  SPI_ROLE_TABLE_COLUMN_HEADER,
  SPI_ROLE_TABLE_ROW_HEADER,
  SPI_ROLE_TEXT,
  SPI_ROLE_TOGGLE_BUTTON,
  SPI_ROLE_TOOL_BAR,
  SPI_ROLE_TOOL_TIP,
  SPI_ROLE_TREE,
  SPI_ROLE_UNKNOWN,
  SPI_ROLE_VIEWPORT,
  SPI_ROLE_WINDOW,
  SPI_ROLE_LAST_DEFINED
} AccessibleRole;

char* AccessibleRole_getName (AccessibleRole role);

G_END_DECLS

#endif
