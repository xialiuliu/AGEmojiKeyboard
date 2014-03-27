//
//  AGEmojiKeyboardView.h
//  AGEmojiKeyboard
//
//  Created by Ayush on 09/05/13.
//  Copyright (c) 2013 Ayush. All rights reserved.
//
// Set as inputView to textfields, this view class gives an
// interface to the user to enter emoji characters.

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AGEmojiKeyboardViewCategoryImage) {
  AGEmojiKeyboardViewCategoryImageRecent,
  AGEmojiKeyboardViewCategoryImageFace,
  AGEmojiKeyboardViewCategoryImageBell,
  AGEmojiKeyboardViewCategoryImageFlower,
  AGEmojiKeyboardViewCategoryImageCar,
  AGEmojiKeyboardViewCategoryImageCharacters
};

@protocol AGEmojiKeyboardViewDelegate;
@protocol AGEmojiKeyboardViewDataSource;

/**
 Keyboard class to present as an alternate.
 This keyboard presents the emojis supported by iOS.
 */
@interface AGEmojiKeyboardView : UIView


@property (nonatomic, weak) id<AGEmojiKeyboardViewDelegate> delegate;
@property (nonatomic, weak) id<AGEmojiKeyboardViewDataSource> dataSource;

/**
 @param frame Frame of the view to be initialised with.

 @param dataSource dataSource is required during the initialization to
 get all the relevent images to present in the view.
 */
- (instancetype)initWithFrame:(CGRect)frame
                   dataSource:(id<AGEmojiKeyboardViewDataSource>)dataSource;

@end


/**
 Protocol to be followed by the dataSource of `AGEmojiKeyboardView`.
 */
@protocol AGEmojiKeyboardViewDataSource <NSObject>

- (UIImage *)emojiKeyboardView:(AGEmojiKeyboardView *)emojiKeyboardView imageForSelectedCategory:(AGEmojiKeyboardViewCategoryImage)category;
/**
 Method called on dataSource to get the category image when selected.

 @param emojiKeyBoardView EmojiKeyBoardView object on which user has tapped.

- (UIImage *)emojiKeyboardView:(AGEmojiKeyboardView *)emojiKeyboardView imageForNonSelectedCategory:(AGEmojiKeyboardViewCategoryImage)category;
 @param category category to get the image for. @see AGEmojiKeyboardViewCategoryImage
 */

/**
 Method called on dataSource to get the category image when not-selected.

 @param emojiKeyBoardView EmojiKeyBoardView object on which user has tapped.

 @param category category to get the image for. @see AGEmojiKeyboardViewCategoryImage
 */

@end


/**
 Protocol to be followed by the delegate of `AGEmojiKeyboardView`.
 */
@protocol AGEmojiKeyboardViewDelegate <NSObject>

/**
 Delegate method called when user taps an emoji button

 @param emojiKeyBoardView EmojiKeyBoardView object on which user has tapped.

 @param emoji Emoji used by user
 */
- (void)emojiKeyBoardView:(AGEmojiKeyboardView *)emojiKeyBoardView didUseEmoji:(NSString *)emoji;

/**
 Delegate method called when user taps on the backspace button

 @param emojiKeyBoardView EmojiKeyBoardView object on which user has tapped.
 */
- (void)emojiKeyBoardViewDidPressBackSpace:(AGEmojiKeyboardView *)emojiKeyBoardView;

@end
