//
//  YModemUtil.h
//  BWProject
//
//  Created by rnd on 2018/7/4.
//  Copyright © 2018年 Radiance Instruments Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YModem.h"


typedef enum : NSUInteger {
    OTAStatusNONE,
    OTAStatusWaiting,
    OTAStatusFirstOrder,
    OTAStatusBinOrder,
    OTAStatusBinOrderDone,
    OTAStatusEnd,
    OTAStatusCAN,
    OTAStatusEOT,
} OTAStatus;

typedef enum : NSUInteger {
    OrderStatusNONE,
    OrderStatusC,
    OrderStatusACK,
    OrderStatusNAK,
    OrderStatusCAN,
    OrderStatusFirst,
} OrderStatus;


//设置代理方法
@protocol YModemUtilDelegate <NSObject>

//写入蓝牙数据
-(void)onWriteBleData:(NSData*) data;

@end

@interface YModemUtil : NSObject

- (instancetype)init:(uint32_t) size;

@property (nonatomic, weak) id<YModemUtilDelegate> delegate;

@property (nonatomic, strong) NSArray  *packetArray;

@property (nonatomic, assign) OTAStatus status;

- (void)setFirmwareHandleOTADataWithOrderStatus:(OrderStatus)status fileName:(NSString *)filename completion:(void(^)(NSInteger current,NSInteger total,NSString *msg))complete;

- (NSData *)prepareFirstPacketWithFileName:(NSString *)filename;

-(void)stopOtaUpgrad;



@end


