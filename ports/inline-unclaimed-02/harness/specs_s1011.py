"""specs_s1011.py - unclaimed-02 batch 11 (docs/20-unclaimed-02.md): ZInputActions::ConvertScanCode (0x438290). The gen
fills the key/value table in the exe's .data (keys from 0x6e492c in 8-byte steps, values at 0x6e4928 + 8k, zero-key
terminator), sets the system interface global 0x70039c and its byte at +0x6e, so both branches and the loop are exercised."""
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _scan(c):
    arg = c.rng.choice([1, 2, 3, 0x10, 0, -1, c.rng.getrandbits(32)])
    n = c.rng.randint(0, 6)
    for k in range(n):
        key = c.rng.choice([1, 2, 3, 0x10, c.rng.getrandbits(32)])
        if c.rng.random() < 0.3:
            key = arg
        c.emu.w32(0x6e492c + 8 * k, key)
        c.emu.w32(0x6e4928 + 8 * k, c.rng.getrandbits(32))
    c.emu.w32(0x6e492c + 8 * n, 0)          # terminator
    sys_ = _rnd(c, 0x100)
    c.emu.w8(sys_ + 0x6e, c.rng.choice([0, 0, 1]))
    c.emu.w32(0x70039c, sys_)
    return [arg]


S(0x438290, 'ZInputActions::ConvertScanCode(int) stdcall', 'stdcall', None, ret='eax', gen=_scan,
  note='unclaimed-02 batch 11; global flag at sys+0x6e returns the arg; else table walk over 8-byte records from 0x6e492c')
