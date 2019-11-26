//
//  RFTransitionAnimation.h
//  MyUtilDemo
//
//  Created by godox on 2019/11/26.
//  Copyright © 2019 RuFeng. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface RFTransitionAnimation : NSObject<UIViewControllerAnimatedTransitioning>

- (instancetype)initWithTargetEdge:(UIRectEdge)targetEdge;

@property (nonatomic, readwrite) UIRectEdge targetEdge;

@end


NS_ASSUME_NONNULL_END
