BFRadialWaveView
=============
[![CocoaPods](https://img.shields.io/cocoapods/v/BFRadialWaveView.svg?style=flat)](https://github.com/bfeher/BFRadialWaveView)

> A mesmerizing view with lots of options. It is meant to be used with [BFRadialWaveHUD](), but you are free to take it :) 

![Animated Screenshot]("Animated Screenshot")


About
---------
_BFRadialWaveView_ is a sublcass of UIView. It displays a radial wave with various options. It was made to be the progress/spinner view for [BFRadialWaveHUD]().

Methods
---------
## Initializer
>Use this when you make a BFRadialWaveView in code.
```objective-c
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
```

## Setup
>Use this when you made a BFRadialWaveView in the storyboard or xib
```objective-c
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
```

### Loading
```objective-c
/** Show a basic view with no progress. */
- (void)show;
```

### Progress
```objective-c
/**
 *  Show a view with progress.
 *
 *  @param progress CGFloat between 0.f and 1.f. The progress to show.
 */
- (void)showProgress:(CGFloat)progress;
```

### Success
```objective-c
/** Show a success view. */
- (void)showSuccess;
```

### Error
```objective-c
/** Show an error view. */
- (void)showError;
```

### Update
```objective-c
/**
 *  Update the progress to a certain value.
 *
 *  @param progress CGFloat between 0.f and 1.f. The progress to show.
 */
- (void)updateProgress:(CGFloat)progress;
```

```objective-c
/**
 *  Update the circle color on the fly.
 *
 *  @param color UIColor to set the circles' strokeColor to.
 */
- (void)updateCircleColor:(UIColor *)color;
```

```objective-c
/**
 *  Update the progress circle color on the fly.
 *
 *  @param color UIColor to set the progress circle's strokeColor to.
 */
- (void)updateProgressCircleColor:(UIColor *)color;
```

### Fun
```objective-c
/**
 *  Activate or deactivate disco mode.
 *
 *  @param on BOOL flag to turn disco mode on (YES) or off (NO).
 */
- (void)disco:(BOOL)on;
```



Properties
---------
```objective-c
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
```

Usage
---------
Add the _BFRadialWaveView_ header and implementation file to your project. (.h & .m)

### Working Example
```objective-c
BFRadialWaveView *radialWaveView = [[BFRadialWaveView alloc] initWithView:self.view
                                                                      circles:BFRadialWaveView_DefaultNumberOfCircles
                                                                        color:nil
                                                                         mode:BFRadialWaveViewMode_Default
                                                                  strokeWidth:BFRadialWaveView_DefaultStrokeWidth
                                                                 withGradient:YES];
[radialWaveView show];
```

### Customized Example
```objective-c
BFRadialWaveView *radialWaveView = [[BFRadialWaveView alloc] initWithView:self.view
                                                                  circles:10
                                                                    color:[UIColor paperColorGray800]
                                                                     mode:BFRadialWaveViewMode_North
                                                              strokeWidth:5.f
                                                             withGradient:NO];
[radialWaveView disco:YES];	// DISCO TAIMU NAU!
[radialWaveView showProgress:someProgressBetweenZeroAndOne];
```

Cocoapods
-------

CocoaPods are the best way to manage library dependencies in Objective-C projects.
Learn more at http://cocoapods.org

Add this to your podfile to add BFRadialWaveView to your project.
```ruby
platform :ios, '7.1'
```


License
--------
_BFRadialWaveView_ uses the MIT License:

> Please see included [LICENSE file](https://raw.githubusercontent.com/bfeher/BFRadialWaveView/master/LICENSE.md).
