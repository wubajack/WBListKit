//
//  WBCollectionSection.m
//  Pods
//
//  Created by fangyuxi on 2017/3/28.
//
//

#import "WBCollectionSection.h"

@interface WBCollectionSection ()

/**
 存放此section关联的items 类型为WBCollectionItem
 */
@property (nonatomic, strong) NSMutableArray *items;

@end

@implementation WBCollectionSection

@synthesize itemCount = _itemCount;

/**
 gets
 */
- (nullable WBCollectionItem *)itemAtIndex:(NSUInteger)index{
    if (index < self.itemCount)
    {
        return [self.items objectAtIndex:index];
    }
    return nil;
}

/**
 inserts
 */
- (void)addItem:(WBCollectionItem *)item
{
    [self insertItem:item atIndex:self.itemCount];
}
- (void)addItems:(NSArray<WBCollectionItem *> *)items
{
    if (items)
    {
        [self.items addObjectsFromArray:items];
    }
}
- (void)insertItem:(WBCollectionItem *)item
           atIndex:(NSUInteger)index
{
    if (item && index <= self.items.count)
    {
        [self.items insertObject:item atIndex:index];
    }
}

/**
 delete
 */
- (void)deleteItem:(WBCollectionItem *)item
{
    [self.items removeObject:item];
}
- (void)deleteItemAtIndex:(NSUInteger)index
{
    if (index < self.items.count)
    {
        [self.items removeObjectAtIndex:index];
    }
}
- (void)deleteAllItems
{
    [self.items removeAllObjects];
}

/**
 exchange replace
 */
- (void)replaceItemAtIndex:(NSUInteger)index
                  withItem:(WBCollectionItem *)item
{
    if (item)
    {
        [self.items replaceObjectAtIndex:index withObject:item];
    }
}
- (void)exchangeItemAtIndex:(NSUInteger)index1
                  withIndex:(NSInteger)index2
{
    if (index1 < self.items.count && index2 < self.items.count)
    {
        [self.items exchangeObjectAtIndex:index1 withObjectAtIndex:index2];
    }
    
}

#pragma mark getter

- (NSMutableArray *)items
{
    if (!_items)
    {
        _items = [NSMutableArray<WBCollectionItem *> array];
    }
    return _items;
}

- (NSUInteger)itemCount
{
    return [self.items count];
}

#pragma mark setter

- (void)setMaker:(WBCollectionSectionMaker * _Nullable)maker{
    _maker = maker;
}

- (void)setIdentifier:(NSString * _Nonnull)identifier{
    _identifier = identifier;
}

- (void)setItemCount:(NSUInteger)itemCount{
    _itemCount = itemCount;
}

@end
