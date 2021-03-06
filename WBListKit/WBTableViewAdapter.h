//
//  WBListKitAdapter.h
//  Pods
//
//  Created by fangyuxi on 2017/3/17.
//
//

#import <Foundation/Foundation.h>
#import "WBListKitAssert.h"
#import "WBListKitMacros.h"
#import "WBTableSectionMaker.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WBListActionToControllerProtocol;

@interface WBTableViewAdapter : NSObject

/**
 可以在'viewWillAppear' 和 'viewDidDisappear' 中调用，用来回调cell/header/footer
 中的 'cancel' 'reload' 方法
 */
- (void)willAppear;
- (void)didDisappear;

@property (nonatomic, weak, readonly) UITableView *tableView;

/**
 you should use these method to manage tableview's and datasource
 please avoid direct use tableview's delegate and datasource property
 */
@property (nonatomic, weak) id tableDataSource;

/**
 get section at index

 @param index 'index'
 */
- (WBTableSectionMaker *)sectionAtIndex:(NSUInteger)index;

/**
 get section with identifier

 @param identifier 'identifier'
 @return section
 */
- (WBTableSectionMaker *)sectionForIdentifier:(NSString *)identifier;

/**
 get index of section
 
 @param maker 'sectionMaker'
 @return index
 */
- (NSUInteger)indexOfSection:(WBTableSectionMaker *)maker;

/**
 append section

 @param block 'block'
 */
- (void)addSection:(void(^)(WBTableSectionMaker *maker))block;

/**
 add section at index

 @param block 'block'
 @param index '指定位置'
 */
- (void)insertSection:(void(^)(WBTableSectionMaker *maker))block
              atIndex:(NSUInteger)index;

/**
 update section

 @param section 'section'
 @param block   'block'
 */
- (void)updateSection:(WBTableSection *)section
            useMaker:(void(^)(WBTableSectionMaker *maker))block;

/**
 更新指定位置的section

 @param index 'index'
 @param block 'block'
 */
- (void)updateSectionAtIndex:(NSUInteger)index
                   useMaker:(void(^)(WBTableSectionMaker *maker))block;


/**
 更新指定的id的section

 @param identifier 'identifier'
 @param block 'block'
 */
- (void)updateSectionForIdentifier:(NSString *)identifier
                           useMaker:(void(^)(WBTableSectionMaker *maker))block;

/**
 删除操作
 */
- (void)deleteSection:(WBTableSection *)section;
- (void)deleteSectionAtIndex:(NSUInteger)index;
- (void)deleteSectionForIdentifier:(NSString *)identifier;
- (void)deleteAllSections;

@end

@interface WBTableViewAdapter (ReloadShortcut)

- (void)reloadRowAtIndex:(NSIndexPath *)indexPath
               animation:(UITableViewRowAnimation)animationType
              usingBlock:(void(^)(WBTableRow *row))block;

- (void)reloadRowAtIndex:(NSInteger )index
    forSectionIdentifier:(NSString *)identifier
               animation:(UITableViewRowAnimation)animationType
              usingBlock:(void(^)(WBTableRow *row))block;

//TO DO 待完善
@end

NS_ASSUME_NONNULL_END

