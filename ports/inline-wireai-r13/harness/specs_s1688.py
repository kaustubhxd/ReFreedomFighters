import struct
"""specs_s1688.py - residue 13 batch 1688: 0x476d30 (Save-style). ZGROUP::Save (0x441790) is hooked with a random al (0 or 1
with random high bits). The saver object has slots 0x60, 0x40, 0x44 (one argument), 0x64 (one argument, random eax) and 0x10
(two arguments, random eax). The array at +0x64 holds 0..3 random entries."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _logger(c, nlog=8):
    """Slot 0x44 (thiscall, one argument): appends every argument to a heap log (the stub recorder keeps only the last call)."""
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(4 * nlog, 16)
    code = b'\x8b\x0d' + struct.pack('<I', cnt)            # mov ecx,[cnt]
    code += b'\x89\xca'                                     # mov edx,ecx
    code += b'\xc1\xe2\x02'                                 # shl edx,2
    code += b'\x81\xc2' + struct.pack('<I', log)            # add edx,log
    code += b'\x8b\x44\x24\x04\x89\x02'                   # mov eax,[esp+4]; mov [edx],eax
    code += b'\xff\x05' + struct.pack('<I', cnt)            # inc [cnt]
    code += b'\x31\xc0\xc2\x04\x00'                       # xor eax,eax; ret 4
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x441790, 1, ret=r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)]), this=True, pop=True)
    saver = obj(c, 0x40, {0x60: stub(c, seq, 1), 0x40: stub(c, seq, 1),
                          0x44: _logger(c), 0x64: stub(c, seq, 1, ret=r.getrandbits(32)),
                          0x10: stub(c, seq, 2, ret=r.getrandbits(32))})
    me = rnd(c, 0x100)
    arr = rnd(c, 16)
    for i in range(4):
        c.emu.w32(arr + 4 * i, r.getrandbits(32))
    c.emu.w32(me + 0x64, arr)
    c.emu.w32(me + 0x5c, r.randint(0, 3))
    c.emu.w32(me + 0x60, r.getrandbits(32))
    c.emu.w32(me + 0x68, r.getrandbits(32))
    c.emu.w32(me + 0x6c, r.getrandbits(32))
    c.emu.w8(me + 0x72, r.choice([0, 1, 0x80]))
    c.emu.w16(me + 0x70, r.getrandbits(16))
    return [me, saver]


S(0x476d30, 'GUESS FUN_476d30', 'thiscall', None, ret='eax', gen=_gen, note='batch1688; Save-style; ZGROUP::Save hooked; ret 4')
