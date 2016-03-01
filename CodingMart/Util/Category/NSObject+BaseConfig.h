//
//  NSObject+BaseConfig.h
//  CodingMart
//
//  Created by Ease on 15/10/8.
//  Copyright © 2015年 net.coding. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (BaseConfig)
+ (NSString *)baseURLStr;
+ (NSString *)codingURLStr;
+ (NSString *)userAgent;
+ (NSString *)appVersion;
+ (NSString *)appBuildVersion;
+ (NSDictionary *)rewardTypeDict;
+ (NSDictionary *)rewardStatusDict;
+ (NSDictionary *)rewardRoleTypeDict;
+ (NSDictionary *)applyStatusDict;
+ (NSDictionary *)rewardStatusStrColorDict;
+ (NSDictionary *)rewardStatusBGColorDict;
+ (NSArray *)currentJobList;
+ (NSArray *)careerYearsList;

@end
