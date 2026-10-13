"""specs_s1407.py - unclaimed-14 batch 7 (slice 13): ZVehicleIf::opaqueCall (0x51ad90, one stack argument, ret 4).

Each case: a random 0x40-byte X with the word at +0x10 in 0..count+2; the count at 0x701730 is 0..4 and the table at
0x701738 holds that many stubs. Each stub (stdcall, ret 4) stores its own immediate at [arg+0x20] so the chosen entry is
visible in the heap. Indices at or past the count tail-jump to 0x51a7d0 (original code), which is run as original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# The fallback chain: 0x51a7d0 (table count 0x701660, entries 0x701668) and 0x504560 (count 0x700e70, entries 0x700e78).
# Each level gets 1..4 stub entries and the index is kept below the total, so no case reaches 0x504560's error path (a
# global object call that is not set up here). Without this, about 64% of cases faulted on both sides.
CHAIN = [(0x701668, 0x701660), (0x700e78, 0x700e70)]


def _chain_levels(c, first_count_addr, first_table):
    levels = [(first_table, first_count_addr)] + CHAIN
    counts = []
    for table, cnt_addr in levels:
        n = c.rng.randint(1, 4)
        counts.append(n)
        c.emu.w32(cnt_addr, n)
        for i in range(n):
            imm = c.rng.getrandbits(32)
            # mov eax,[esp+4]; mov dword ptr [eax+0x20], imm32; ret 4
            code = b'\x8b\x44\x24\x04' + b'\xc7\x40\x20' + imm.to_bytes(4, 'little') + b'\xc2\x04\x00'
            m = c.emu.alloc(len(code) + 16, 16)
            c.emu.wbytes(m, code)
            c.emu.w32(table + 4 * i, m)
    return sum(counts)


def _opaque(c):
    total = _chain_levels(c, 0x701730, 0x701738)
    x = _rnd(c, 0x40)
    c.emu.wbytes(x + 0x10, c.rng.randint(0, total - 1).to_bytes(2, 'little'))
    return [x]


S(0x51ad90, 'ZVehicleIf::opaqueCall (unknown) stdcall', 'stdcall', None, ret=None, gen=_opaque,
  note='unclaimed-14 batch 7; table at 0x701738 count 0x701730; fallback tail-jumps to 0x51a7d0 (original)')
