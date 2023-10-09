/**
 * version contorl
 * XXX_VERSION = publish_mode-date-time-publish_times
 *          publish_mode:
 *                  RLS :   release version
 *                  TEST:   test version
 *                  DEV :   develop version
 *          date-time:
 *                          publish datetime
 *          publish_times: 
 *                          publish times in the day(date-time)
 *
 */
#define LIBECB_VERSION DEV-20221128-144409-0002

inline static const char *show_version(){
    return ECB_STRINGIFY(LIBECB_VERSION)
}
