#import <UIKit/UIKit.h>
#import "HRColorPickerViewController.h"

@class WPEditorField;
@class WPEditorView;
@class WPEditorViewController;

typedef enum
{
    kWPEditorViewControllerModePreview = 0,
    kWPEditorViewControllerModeEdit
}
WPEditorViewControllerMode;

@protocol WPEditorViewControllerDelegate <NSObject>
@optional

- (void)editorDidBeginEditing:(WPEditorViewController *)editorController;
- (void)editorDidEndEditing:(WPEditorViewController *)editorController;
- (void)editorDidFinishLoadingDOM:(WPEditorViewController*)editorController;
- (void)editorViewController:(WPEditorViewController *)editorController
             titleWillChange:(NSString*)title;
- (void)editorTextDidChange:(WPEditorViewController *)editorController;

- (void)editorDidPressMedia:(WPEditorViewController *)editorController;

/**
 *	@brief		Received when the field is created and can be used.
 *  @details    The editor fields will be nil before this method is called.  This is because editor
 *              fields are created as part of the process of loading the HTML.
 *
 *	@param		editorView		The editor view.
 *	@param		field			The new field.
 */
- (void)editorViewController:(WPEditorViewController*)editorViewController
                fieldCreated:(WPEditorField*)field;

@end

@class ZSSBarButtonItem;

@interface WPEditorViewController : UIViewController

@property (nonatomic, weak) id<WPEditorViewControllerDelegate> delegate;
@property (nonatomic, copy) NSString *titleText;
@property (nonatomic, copy) NSString *bodyText;

#pragma mark - Properties: Editor View
@property (nonatomic, strong, readonly) WPEditorView *editorView;

#pragma mark - Coloring

/**
 *	@brief		The background color for the toolbar.
 */
@property (nonatomic, copy, readwrite) UIColor* toolbarBackgroundColor;

/**
 *	@brief		The border color for the toolbar.
 */
@property (nonatomic, copy, readwrite) UIColor* toolbarBorderColor;

/**
 *  Color to tint the toolbar items
 */
@property (nonatomic, strong) UIColor *toolbarItemTintColor;

/**
 *  Color to tint selected items
 */
@property (nonatomic, strong) UIColor *toolbarItemSelectedTintColor;

#pragma mark - Initializers

/**
 *	@brief		Initializes the VC with the specified mode.
 *
 *	@param		mode	The mode to initialize the VC in.
 *
 *	@returns	The initialized object.
 */
- (instancetype)initWithMode:(WPEditorViewControllerMode)mode;

#pragma mark - Editing

/**
 *	@brief		Call this method to know if the VC is in edit mode.
 *	@details	Edit mode has to be manually turned on and off, and is not reliant on fields gaining
 *				or losing focus.
 *
 *	@returns	YES if the VC is in edit mode, NO otherwise.
 */
- (BOOL)isEditing;

/**
 *	@brief		Starts editing.
 */
- (void)startEditing;

/**
 *  @brief		Stop all editing activities.
 */
- (void)stopEditing;

#pragma mark - Override these in subclasses

/**
 *  Gets called when the insert URL picker button is tapped in an alertView
 *
 *  @warning The default implementation of this method is blank and does nothing
 */
- (void)showInsertURLAlternatePicker;

/**
 *  Gets called when the insert Image picker button is tapped in an alertView
 *
 *  @warning The default implementation of this method is blank and does nothing
 */
- (void)showInsertImageAlternatePicker;

@end
