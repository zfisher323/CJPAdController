//
//  CJPAdController.h
//  ChrisJP
//
//  Created by Chris Phillips on 19/11/2011.
//  Copyright (c) 2011 ChrisJP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <iAd/iAd.h>
#import "GADBannerView.h"

// Display iAds?
static BOOL const kUseiAd = YES;

// Display AdMob ads?
static BOOL const kUseAdMob = YES;

// Set which ads should be initially displayed and preferred ("iAd" or "AdMob")
static NSString * const kDefaultAds = @"iAd";

// Your AdMob publisher ID
static NSString * const kAdMobID = @"a14f255d715fe96";

// Use AdMob's "Smart" size banners (will fill full width of device)
// If set to NO, 320x50 ads will be used for iPhone/iPod and 728x90 for iPad
static BOOL const kUseAdMobSmartSize = YES;

// Seconds to wait before displaying ad after the view appears (0.0 = instant)
static float const kWaitTime = 2.0;

// Name of UserDefaults key for if ads have been purchased (you can ignore this if you don't have an IAP to remove ads)
static NSString * const kAdsPurchasedKey = @"adRemovalPurchased";

// Are you testing? Setting to YES will NSLog various events
static BOOL const kAdTesting = YES;


@interface CJPAdController : NSObject <ADBannerViewDelegate, GADBannerViewDelegate>

@property (nonatomic, retain) ADBannerView      *iAdView;
@property (nonatomic, retain) GADBannerView     *adMobView;
@property (nonatomic, retain) UIView            *containerView;
@property (nonatomic, assign) UIView            *parentView;
@property (nonatomic, assign) UIViewController  *parentViewController;
@property (nonatomic, assign) UIView            *previousView;
@property (nonatomic, assign) BOOL              showingiAd;
@property (nonatomic, assign) BOOL              showingAdMob;
@property (nonatomic, assign) BOOL              adsRemoved;


+ (CJPAdController *)sharedManager;
- (void)addBannerToViewController:(UIViewController *)viewController;
- (void)createBanner:(NSString *)adType;
- (void)removeBanner:(NSString *)adType permanently:(BOOL)permanent;
- (void)resizeViewForAdType:(NSString *)adType showOrHide:(NSString *)showHide afterRotation:(BOOL)isAfterRotation;
- (void)rotateAdToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation;
- (void)fixAdViewAfterRotation;

@end