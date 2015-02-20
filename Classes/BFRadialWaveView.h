//
//  BFRadialWaveView.h
//  BFRadialWaveHUD
//
//  Created by Bence Feher on 2/13/15.
//  Copyright (c) 2015 Bence Feher. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, BFRadialWaveViewMode) {
    BFRadialWaveViewMode_Default,
    BFRadialWaveViewMode_KuneKune,
    BFRadialWaveViewMode_North,
    BFRadialWaveViewMode_NorthEast,
    BFRadialWaveViewMode_East,
    BFRadialWaveViewMode_SouthEast,
    BFRadialWaveViewMode_South,
    BFRadialWaveViewMode_SouthWest,
    BFRadialWaveViewMode_West,
    BFRadialWaveViewMode_NorthWest,
};

extern NSInteger const BFRadialWaveView_DefaultNumberOfCircles;
extern CGFloat const BFRadialWaveView_DefaultStrokeWidth;


@class BFRadialWaveView;
@protocol BFRadialWaveViewDelegate <NSObject>
/**
 *  The protocol message to send our delegate on success.
 *
 *  @param sender The BFRadialWaveView that sent this message.
 */
- (void)successfulCompletionWithRadialWaveView:(BFRadialWaveView *)sender;

/**
 *  The protocol message to send our delegate on failure.
 *
 *  @param sender The BFRadialWaveView that sent this message.
 */
- (void)errorCompletionWithRadialWaveView:(BFRadialWaveView *)sender;
@end


@interface BFRadialWaveView : UIView
#pragma mark - Custom Initializers
/**
 *  Custom initializer. Use this when you make a BFRadialWaveView in code.
 *
 *  @param container       A UIView to place this one in.
 *  @param numberOfCircles NSInteger number of circles. Min = 3, Max = 20.
 *  @param circleColor     UIColor to set the circles' strokeColor to.
 *  @param mode            BFRadialWaveViewMode.
 *  @param strokeWidth     CGFloat stroke width of the circles.
 *  @param withGradient    BOOL flag to decide whether or not to draw a gradient in the background.
 *
 *  @return Returns A BFRadialWaveView! Aww yiss!
 */
- (instancetype)initWithView:(UIView *)container
                     circles:(NSInteger)numberOfCircles
                       color:(UIColor *)circleColor
                        mode:(BFRadialWaveViewMode)mode
                 strokeWidth:(CGFloat)strokeWidth
                withGradient:(BOOL)withGradient;


#pragma mark - Setup
/**
 *  Setup. Use this when you made a BFRadialWaveView in the storyboard or xib.
 *
 *  @param container       A UIView to place this one in.
 *  @param numberOfCircles NSInteger number of circles. Min = 3, Max = 20.
 *  @param circleColor     UIColor to set the circles' strokeColor to.
 *  @param mode            BFRadialWaveViewMode.
 *  @param strokeWidth     CGFloat stroke width of the circles.
 *  @param withGradient    BOOL flag to decide whether or not to draw a gradient in the background.
 */
- (void)setupWithView:(UIView *)container
              circles:(NSInteger)numberOfCircles
                color:(UIColor *)circleColor
                 mode:(BFRadialWaveViewMode)mode
          strokeWidth:(CGFloat)strokeWidth
         withGradient:(BOOL)withGradient;


#pragma mark - Loading
/** Show a basic view with no progress. */
- (void)show;


#pragma mark - Progress
/**
 *  Show a view with progress.
 *
 *  @param progress CGFloat between 0.f and 1.f. The progress to show.
 */
- (void)showProgress:(CGFloat)progress;


#pragma mark - Success
/** Show a success view. */
- (void)showSuccess;


#pragma mark - Error
/** Show an error view. */
- (void)showError;


#pragma mark - Update
/**
 *  Update the progress to a certain value.
 *
 *  @param progress CGFloat between 0.f and 1.f. The progress to show.
 */
- (void)updateProgress:(CGFloat)progress;

/**
 *  Update the circle color on the fly.
 *
 *  @param color UIColor to set the circles' strokeColor to.
 */
- (void)updateCircleColor:(UIColor *)color;

/**
 *  Update the progress circle color on the fly.
 *
 *  @param color UIColor to set the progress circle's strokeColor to.
 */
- (void)updateProgressCircleColor:(UIColor *)color;


#pragma mark - Fun
/**
 *  Activate or deactivate disco mode.
 *
 *  @param on BOOL flag to turn disco mode on (YES) or off (NO).
 */
- (void)disco:(BOOL)on;


#pragma mark - Properties
/** The diameter of the view (including progress circle). */
@property (nonatomic, readonly) CGFloat diameter;

/** The color to set the success checkmark to. By default it is the same as the circleColor passed into the initializer or the setup. */
@property UIColor *checkmarkColor;

/** The color to set the failure cross to. By default it is the same as the circleColor passed into the initializer or the setup. */
@property UIColor *crossColor;

/** An NSArray of colors to use for disco mode. By default it is the rainbow. */
@property (nonatomic) NSArray *discoColors;

/** CGFloat speed for the disco animation. Default is 0.33f. */
@property (nonatomic) CGFloat discoSpeed;

/** BFRadialWaveViewDelegate delegate for our protocol. */
@property id <BFRadialWaveViewDelegate> delegate;

@end
