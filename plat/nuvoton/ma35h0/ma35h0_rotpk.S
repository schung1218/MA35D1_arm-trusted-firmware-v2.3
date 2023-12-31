/*
 * Copyright (c) 2023 ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

	.global ma35h0_rotpk_hash
	.global ma35h0_rotpk_hash_end
ma35h0_rotpk_hash:
	/* DER header */
	.byte 0x30, 0x31, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48
	.byte 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x04, 0x20
	/* SHA256 */
	.incbin ROTPK_HASH
ma35h0_rotpk_hash_end:
