//
//  EATipView.h
//  CodingMart
//
//  Created by Ease on 16/8/8.
//  Copyright © 2016年 net.coding. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EATipView : UIView
@property (strong, nonatomic) NSString *title, *tipStr, *text;
@property (strong, nonatomic) NSAttributedString *attrStr;
@property (assign, nonatomic, readonly) BOOL isShowing;
@property (copy, nonatomic) void(^leftBtnBlock)();
@property (copy, nonatomic) void(^rightBtnBlock)();

- (void)setLeftBtnTitle:(NSString *)title block:(void(^)())block;
- (void)setRightBtnTitle:(NSString *)title block:(void(^)())block;
- (void)showInView:(UIView *)view;
+ (instancetype)instancetypeWithTitle:(NSString *)title tipStr:(NSString *)tipStr;
+ (instancetype)instancetypeWithTitle:(NSString *)title attrStr:(NSAttributedString *)attrStr;
+ (void)showAllowNotificationTipInView:(UIView *)view;
- (void)dismiss;
@end
