/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

#include "ble_gap_conn.h"
#include "ble_serialization.h"

uint32_t ble_gap_tx_power_set_req_dec(uint8_t const * const p_buf,
                                      uint32_t              packet_len,
                                      int8_t *              p_tx_power)
{
    SER_ASSERT_NOT_NULL(p_buf);
    SER_ASSERT_NOT_NULL(p_tx_power);

    uint32_t err_code = NRF_SUCCESS;
    uint32_t index    = SER_CMD_DATA_POS;

    err_code = uint8_t_dec(p_buf, packet_len, &index, p_tx_power);
    SER_ASSERT(err_code == NRF_SUCCESS, err_code);

    SER_ASSERT_LENGTH_EQ(index, packet_len);

    return NRF_SUCCESS;
}

uint32_t ble_gap_tx_power_set_rsp_enc(uint32_t         return_code,
                                      uint8_t * const  p_buf,
                                      uint32_t * const p_buf_len)
{
    return ser_ble_cmd_rsp_status_code_enc(SD_BLE_GAP_TX_POWER_SET, return_code, p_buf, p_buf_len);
}
