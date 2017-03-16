//
//  TIMManager+EA.m
//  CodingMart
//
//  Created by Ease on 2017/3/16.
//  Copyright © 2017年 net.coding. All rights reserved.
//

#import "TIMManager+EA.h"
#import "CodingNetAPIClient.h"
#import "Login.h"

@implementation TIMManager (EA)
+ (void)setupConfig{
    TIMManager *timManager = [TIMManager sharedInstance];
    [timManager disableCrashReport];
    [timManager setMessageListener:[TIMMessageListenerImp new]];
    [timManager setUserStatusListener:[TIMUserStatusListenerImp new]];
    [timManager initSdk:kTimAppidAt3rd.intValue];
}
+ (void)loginBlock:(void (^)(NSString *errorMsg))block{
    if ([TIMManager sharedInstance].getLoginStatus == TIM_STATUS_LOGINING) {
        return;
    }
    [[CodingNetAPIClient sharedJsonClient] requestJsonDataWithPath:@"api/im/user" withParams:nil withMethodType:Get andBlock:^(id data, NSError *error) {
        if (error) {
            block(error.localizedDescription);
            return ;
        }
        NSDictionary *user = [data[@"user"] firstObject];
        NSString *userSig = user[@"identifier"];
        
        TIMLoginParam *loginParam = [TIMLoginParam new];
        loginParam.accountType = kTimAccountType;
        loginParam.sdkAppId = kTimAppidAt3rd.intValue;
        loginParam.appidAt3rd = kTimAppidAt3rd;
        loginParam.identifier = [Login curLoginUser].global_key;
        loginParam.userSig = userSig;
        [[TIMManager sharedInstance] login:loginParam succ:^(){
            block(nil);
        } fail:^(int code, NSString *msg) {
            [NSObject showHudTipStr:msg];
            block(msg);
        }];
    }];
}

@end
