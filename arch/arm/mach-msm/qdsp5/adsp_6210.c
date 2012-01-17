/* arch/arm/mach-msm/qdsp5/adsp_6210.h
 *
 * Copyright (c) 2008-2009, Code Aurora Forum. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "adsp.h"

/* Firmware modules */
typedef enum {
	QDSP_MODULE_KERNEL,
	QDSP_MODULE_AFETASK,
	QDSP_MODULE_AUDPLAY0TASK,
	QDSP_MODULE_AUDPLAY1TASK,
	QDSP_MODULE_AUDPPTASK,
	QDSP_MODULE_VIDEOTASK,
	QDSP_MODULE_VIDEO_AAC_VOC,
	QDSP_MODULE_PCM_DEC,
	QDSP_MODULE_AUDIO_DEC_MP3,
	QDSP_MODULE_AUDIO_DEC_AAC,
	QDSP_MODULE_AUDIO_DEC_WMA,
	QDSP_MODULE_HOSTPCM,
	QDSP_MODULE_DTMF,
	QDSP_MODULE_AUDRECTASK,
	QDSP_MODULE_AUDPREPROCTASK,
	QDSP_MODULE_SBC_ENC,
	QDSP_MODULE_VOC,
	QDSP_MODULE_VOC_PCM,
	QDSP_MODULE_VOCENCTASK,
	QDSP_MODULE_VOCDECTASK,
	QDSP_MODULE_VOICEPROCTASK,
	QDSP_MODULE_VIDEOENCTASK,
	QDSP_MODULE_VFETASK,
	QDSP_MODULE_WAV_ENC,
	QDSP_MODULE_AACLC_ENC,
	QDSP_MODULE_VIDEO_AMR,
	QDSP_MODULE_VOC_AMR,
	QDSP_MODULE_VOC_EVRC,
	QDSP_MODULE_VOC_13K,
	QDSP_MODULE_VOC_FGV,
	QDSP_MODULE_DIAGTASK,
	QDSP_MODULE_JPEGTASK,
	QDSP_MODULE_LPMTASK,
	QDSP_MODULE_QCAMTASK,
	QDSP_MODULE_MODMATHTASK,
	QDSP_MODULE_AUDPLAY2TASK,
	QDSP_MODULE_AUDPLAY3TASK,
	QDSP_MODULE_AUDPLAY4TASK,
	QDSP_MODULE_GRAPHICSTASK,
	QDSP_MODULE_MIDI,
	QDSP_MODULE_GAUDIO,
	QDSP_MODULE_VDEC_LP_MODE,
	QDSP_MODULE_MAX,
} qdsp_module_type;

#define QDSP_RTOS_MAX_TASK_ID  19U

/* Table of modules indexed by task ID for the GAUDIO image */
static qdsp_module_type qdsp_gaudio_task_to_module_table[] = {
	QDSP_MODULE_KERNEL,
	QDSP_MODULE_AFETASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_AUDPPTASK,
	QDSP_MODULE_AUDPLAY0TASK,
	QDSP_MODULE_AUDPLAY1TASK,
	QDSP_MODULE_AUDPLAY2TASK,
	QDSP_MODULE_AUDPLAY3TASK,
	QDSP_MODULE_AUDPLAY4TASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_AUDRECTASK,
	QDSP_MODULE_AUDPREPROCTASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_GRAPHICSTASK,
	QDSP_MODULE_MAX
};

/* Queue offset table indexed by queue ID for the GAUDIO image */
static uint32_t qdsp_gaudio_queue_offset_table[] = {
	QDSP_RTOS_NO_QUEUE,  /* QDSP_lpmCommandQueue              */
	0x3be,               /* QDSP_mpuAfeQueue                  */
	0x3ee,               /* QDSP_mpuGraphicsCmdQueue          */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuModmathCmdQueue           */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuVDecCmdQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuVDecPktQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuVEncCmdQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_rxMpuDecCmdQueue             */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_rxMpuDecPktQueue             */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_txMpuEncQueue                */
	0x3c2,               /* QDSP_uPAudPPCmd1Queue             */
	0x3c6,               /* QDSP_uPAudPPCmd2Queue             */
	0x3ca,               /* QDSP_uPAudPPCmd3Queue             */
	0x3da,               /* QDSP_uPAudPlay0BitStreamCtrlQueue */
	0x3de,               /* QDSP_uPAudPlay1BitStreamCtrlQueue */
	0x3e2,               /* QDSP_uPAudPlay2BitStreamCtrlQueue */
	0x3e6,               /* QDSP_uPAudPlay3BitStreamCtrlQueue */
	0x3ea,               /* QDSP_uPAudPlay4BitStreamCtrlQueue */
	0x3ce,               /* QDSP_uPAudPreProcCmdQueue         */
	0x3d6,               /* QDSP_uPAudRecBitStreamQueue       */
	0x3d2,               /* QDSP_uPAudRecCmdQueue             */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPJpegActionCmdQueue         */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPJpegCfgCmdQueue            */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPVocProcQueue               */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_vfeCommandQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_vfeCommandScaleQueue         */
	QDSP_RTOS_NO_QUEUE   /* QDSP_vfeCommandTableQueue         */
};

/* Table of modules indexed by task ID for the COMBO image */
static qdsp_module_type qdsp_combo_task_to_module_table[] = {
	QDSP_MODULE_KERNEL,
	QDSP_MODULE_AFETASK,
	QDSP_MODULE_VOCDECTASK,
	QDSP_MODULE_VOCENCTASK,
	QDSP_MODULE_VIDEOTASK,
	QDSP_MODULE_VIDEOENCTASK,
	QDSP_MODULE_VOICEPROCTASK,
	QDSP_MODULE_VFETASK,
	QDSP_MODULE_JPEGTASK,
	QDSP_MODULE_AUDPPTASK,
	QDSP_MODULE_AUDPLAY0TASK,
	QDSP_MODULE_AUDPLAY1TASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_LPMTASK,
	QDSP_MODULE_AUDRECTASK,
	QDSP_MODULE_AUDPREPROCTASK,
	QDSP_MODULE_MODMATHTASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX
};

/* Queue offset table indexed by queue ID for the COMBO image */
static uint32_t qdsp_combo_queue_offset_table[] = {
	0x585,               /* QDSP_lpmCommandQueue              */
	0x52d,               /* QDSP_mpuAfeQueue                  */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuGraphicsCmdQueue          */
	0x541,               /* QDSP_mpuModmathCmdQueue           */
	0x555,               /* QDSP_mpuVDecCmdQueue              */
	0x559,               /* QDSP_mpuVDecPktQueue              */
	0x551,               /* QDSP_mpuVEncCmdQueue              */
	0x535,               /* QDSP_rxMpuDecCmdQueue             */
	0x539,               /* QDSP_rxMpuDecPktQueue             */
	0x53d,               /* QDSP_txMpuEncQueue                */
	0x55d,               /* QDSP_uPAudPPCmd1Queue             */
	0x561,               /* QDSP_uPAudPPCmd2Queue             */
	0x565,               /* QDSP_uPAudPPCmd3Queue             */
	0x575,               /* QDSP_uPAudPlay0BitStreamCtrlQueue */
	0x579,               /* QDSP_uPAudPlay1BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay2BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay3BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay4BitStreamCtrlQueue */
	0x569,               /* QDSP_uPAudPreProcCmdQueue         */
	0x571,               /* QDSP_uPAudRecBitStreamQueue       */
	0x56d,               /* QDSP_uPAudRecCmdQueue             */
	0x581,               /* QDSP_uPJpegActionCmdQueue         */
	0x57d,               /* QDSP_uPJpegCfgCmdQueue            */
	0x531,               /* QDSP_uPVocProcQueue               */
	0x545,               /* QDSP_vfeCommandQueue              */
	0x54d,               /* QDSP_vfeCommandScaleQueue         */
	0x549                /* QDSP_vfeCommandTableQueue         */
};

/* Table of modules indexed by task ID for the QTV_LP image */
static qdsp_module_type qdsp_qtv_lp_task_to_module_table[] = {
	QDSP_MODULE_KERNEL,
	QDSP_MODULE_AFETASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_VIDEOTASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_AUDPPTASK,
	QDSP_MODULE_AUDPLAY0TASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_AUDRECTASK,
	QDSP_MODULE_AUDPREPROCTASK,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX,
	QDSP_MODULE_MAX
};

/* Queue offset table indexed by queue ID for the QTV_LP image */
static uint32_t qdsp_qtv_lp_queue_offset_table[] = {
	QDSP_RTOS_NO_QUEUE,  /* QDSP_lpmCommandQueue              */
	0x40c,               /* QDSP_mpuAfeQueue                  */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuGraphicsCmdQueue          */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuModmathCmdQueue           */
	0x410,               /* QDSP_mpuVDecCmdQueue              */
	0x414,               /* QDSP_mpuVDecPktQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_mpuVEncCmdQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_rxMpuDecCmdQueue             */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_rxMpuDecPktQueue             */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_txMpuEncQueue                */
	0x41c,               /* QDSP_uPAudPPCmd1Queue             */
	0x420,               /* QDSP_uPAudPPCmd2Queue             */
	0x424,               /* QDSP_uPAudPPCmd3Queue             */
	0x430,               /* QDSP_uPAudPlay0BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay1BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay2BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay3BitStreamCtrlQueue */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPAudPlay4BitStreamCtrlQueue */
	0x418,               /* QDSP_uPAudPreProcCmdQueue         */
	0x42c,               /* QDSP_uPAudRecBitStreamQueue       */
	0x428,               /* QDSP_uPAudRecCmdQueue             */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPJpegActionCmdQueue         */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPJpegCfgCmdQueue            */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_uPVocProcQueue               */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_vfeCommandQueue              */
	QDSP_RTOS_NO_QUEUE,  /* QDSP_vfeCommandScaleQueue         */
	QDSP_RTOS_NO_QUEUE   /* QDSP_vfeCommandTableQueue         */
};

/* Tables to convert tasks to modules */
static uint32_t *qdsp_task_to_module[] = {
	qdsp_combo_task_to_module_table,
	qdsp_gaudio_task_to_module_table,
	qdsp_qtv_lp_task_to_module_table,
};

/* Tables to retrieve queue offsets */
static uint32_t *qdsp_queue_offset_table[] = {
	qdsp_combo_queue_offset_table,
	qdsp_gaudio_queue_offset_table,
	qdsp_qtv_lp_queue_offset_table,
};

#define QDSP_MODULE(n) \
	{ .name = #n, .pdev_name = "adsp_" #n, .id = QDSP_MODULE_##n }

static struct adsp_module_info module_info[] = {
	QDSP_MODULE(AUDPPTASK),
	QDSP_MODULE(AUDRECTASK),
	QDSP_MODULE(AUDPREPROCTASK),
	QDSP_MODULE(VFETASK),
	QDSP_MODULE(QCAMTASK),
	QDSP_MODULE(LPMTASK),
	QDSP_MODULE(JPEGTASK),
	QDSP_MODULE(VIDEOTASK),
	QDSP_MODULE(VDEC_LP_MODE),
};

int adsp_init_info(struct adsp_info *info)
{
	info->send_irq =   0x00c00200;
	info->read_ctrl =  0x00400038;
	info->write_ctrl = 0x00400034;

	info->max_msg16_size = 193;
	info->max_msg32_size = 8;

	info->max_task_id = 16;
	info->max_module_id = QDSP_MODULE_MAX - 1;
	info->max_queue_id = QDSP_QUEUE_MAX;
	info->max_image_id = 2;
	info->queue_offset = qdsp_queue_offset_table;
	info->task_to_module = qdsp_task_to_module;

	info->module_count = ARRAY_SIZE(module_info);
	info->module = module_info;
	return 0;
}
