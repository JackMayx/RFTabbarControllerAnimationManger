# RFTabbarControllerAnimationManger

[![CI Status](https://img.shields.io/travis/马永祥/RFTabbarControllerAnimationManger.svg?style=flat)](https://travis-ci.org/马永祥/RFTabbarControllerAnimationManger)
[![Version](https://img.shields.io/cocoapods/v/RFTabbarControllerAnimationManger.svg?style=flat)](https://cocoapods.org/pods/RFTabbarControllerAnimationManger)
[![License](https://img.shields.io/cocoapods/l/RFTabbarControllerAnimationManger.svg?style=flat)](https://cocoapods.org/pods/RFTabbarControllerAnimationManger)
[![Platform](https://img.shields.io/cocoapods/p/RFTabbarControllerAnimationManger.svg?style=flat)](https://cocoapods.org/pods/RFTabbarControllerAnimationManger)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.
```
/// 创建滑动手势
 		var panGestureRecognizer:UIPanGestureRecognizer!

/// 添加手势
 		panGestureRecognizer = UIPanGestureRecognizer(target: self, action: #selector(panGestureRecognizerMethod(pan:)))
        self.view.addGestureRecognizer(panGestureRecognizer)

///复制一下实现方法
    @objc func panGestureRecognizerMethod(pan : UIPanGestureRecognizer){
        if (self.transitionCoordinator != nil){
            return
        }
        
        if pan.state == .began || pan.state == .changed{
            
            self.beginInteractiveTransitionIfPossible(pan: pan)
            
        }

    }
    func beginInteractiveTransitionIfPossible(pan:UIPanGestureRecognizer){
        let translation = pan.translation(in: self.view)
        if (translation.x > 0.0 && self.selectedIndex > 0){
            self.selectedIndex = self.selectedIndex - 1
        }else if (translation.x < 0.0 && self.selectedIndex + 1 < self.viewControllers!.count){
            self.selectedIndex = self.selectedIndex + 1
        }
    }


  ///实现 tabBarController的UITabBarControllerDelegate代理
  func tabBarController(_ tabBarController: UITabBarController, animationControllerForTransitionFrom fromVC: UIViewController, to toVC: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        
        /// 可以屏蔽点击item时的动画效果
        if self.panGestureRecognizer.state == .began || self.panGestureRecognizer.state == .changed{
            let arrayController = tabBarController.viewControllers
            let toVcIndex = arrayController!.firstIndex(of: toVC)
            let formVcIndex = arrayController!.firstIndex(of: fromVC)
            
            if toVcIndex! > formVcIndex!{
                return RFTransitionAnimation(targetEdge: .left) as? UIViewControllerAnimatedTransitioning
                
            }else{
                return RFTransitionAnimation(targetEdge: .right) as? UIViewControllerAnimatedTransitioning
            }
        }else{
            return nil
        }
        
        
    }
    func tabBarController(_ tabBarController: UITabBarController, interactionControllerFor animationController: UIViewControllerAnimatedTransitioning) -> UIViewControllerInteractiveTransitioning? {
        if self.panGestureRecognizer.state == .began || self.panGestureRecognizer.state == .changed{
            
            return RFPercentDrivenInteractiveTransition(gestureRecognizer: self.panGestureRecognizer)
            
        }else{
            return nil
        }
        
    }

```

## Requirements

## Installation

RFTabbarControllerAnimationManger is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'RFTabbarControllerAnimationManger'
```

## Author

马永祥, 469994861@qq.com

## License

RFTabbarControllerAnimationManger is available under the MIT license. See the LICENSE file for more info.
