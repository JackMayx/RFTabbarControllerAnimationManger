//
//  RFPercentDrivenInteractiveTransition.h
//  MyUtilDemo
//
//  Created by godox on 2019/11/26.
//  Copyright © 2019 RuFeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RFPercentDrivenInteractiveTransition : UIPercentDrivenInteractiveTransition


- (instancetype)initWithGestureRecognizer:(UIPanGestureRecognizer *)gestureRecognizer NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
