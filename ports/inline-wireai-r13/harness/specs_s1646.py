"""specs_s1646.py - residue 13 batch 1646: ZMoveOnSpline::RegisterWithVisionSystem (0x513d10). The system object (global
0x70039c) has its manager at +0x9b (R) with slots 0x4c, 0x58, 0x114 and the object M at +0xadc (slot 0x25c). The geom
GetSize (0x4db7c0) is a Python hook that writes three random floats. The lookup chain is T (0x100 -> C, slot 0x84),
and the list object obj24 (+0x18 = Q). Q's slot 0x5c is raw code: it writes 1 (and counts down) or 0 into the
out pointer, so the loop runs 0..3 times."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj, HOOKED

GETSIZE = 0x4db7c0


def _rf(c):
    r = c.rng
    k = r.random()
    if k < 0.8:
        return r.uniform(-50, 50)
    return r.choice([0.0, -0.0, float('inf'), float('nan'), 1e30])


def _wf(c, v):
    a = c.emu.alloc(4, 4)
    c.emu.wf32(a, v)
    return a


def _getsize(c, seq, vals):
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        out = e.r32(e.reg('esp') + 4)
        for i, v in enumerate(vals):
            e.wf32(out + 4 * i, v)
        n = e.r32(seq.addr) + 1
        e.w32(seq.addr, n)
        e.w32(rec, n)
        e.ret(eax=0, argbytes=4)
    HOOKED.add(GETSIZE)
    c.emu.hook(GETSIZE, h)
    return rec


def _q5c(c, cnt, h):
    # mov eax,[esp+4]; mov ecx,[cnt]; test ecx,ecx; jz zero; dec [cnt]; mov [eax],1; jmp done;
    # zero: mov [eax],0; done: mov eax,h; ret 4
    code = b'\x8b\x44\x24\x04'
    code += b'\x8b\x0d' + struct.pack('<I', cnt)
    code += b'\x85\xc9'
    code += b'\x74\x0e'
    code += b'\xff\x0d' + struct.pack('<I', cnt)
    code += b'\xc7\x00' + struct.pack('<I', 1)
    code += b'\xeb\x06'
    code += b'\xc7\x00' + struct.pack('<I', 0)
    code += b'\xb8' + struct.pack('<I', h & 0xffffffff)
    code += b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _log130(c, id2):
    """Slot 0x130 (thiscall, 3 args): logs arg0, arg1 and the two dwords at arg2 into a 32-byte entry, and for the
    message id2 call the two dwords after them too (the vision buffer holds x, y, z). The entry index is a heap dword,
    so the log compares every call, not only the last one."""
    logi = c.emu.alloc(4, 4)
    log = c.emu.alloc(32 * 8, 16)
    code = b'\x8b\x0d' + struct.pack('<I', logi)                  # mov ecx,[logi]
    code += b'\x89\xca'                                           # mov edx,ecx
    code += b'\xc1\xe2\x05'                                      # shl edx,5
    code += b'\x81\xc2' + struct.pack('<I', log)                 # add edx,log
    code += b'\x8b\x44\x24\x04\x89\x02'                        # mov eax,[esp+4]; mov [edx],eax
    code += b'\x8b\x44\x24\x08\x89\x42\x04'                    # mov eax,[esp+8]; mov [edx+4],eax
    code += b'\x8b\x44\x24\x0c\x8b\x08\x89\x4a\x08'            # mov eax,[esp+12]; mov ecx,[eax]; mov [edx+8],ecx
    code += b'\x8b\x48\x04\x89\x4a\x0c'                        # mov ecx,[eax+4]; mov [edx+12],ecx
    code += b'\x8b\x44\x24\x08\x3d' + struct.pack('<I', id2 & 0xffff)   # mov eax,[esp+8]; cmp eax,id2
    code += b'\x75\x10'                                           # jne skip (16 bytes below)
    code += b'\x8b\x44\x24\x0c\x8b\x48\x08\x89\x4a\x10'        # mov eax,[esp+12]; mov ecx,[eax+8]; mov [edx+16],ecx
    code += b'\x8b\x48\x0c\x89\x4a\x14'                        # mov ecx,[eax+12]; mov [edx+20],ecx
    code += b'\xff\x05' + struct.pack('<I', logi)                # skip: inc [logi]
    code += b'\x31\xc0\xc2\x0c\x00'                            # xor eax,eax; ret 12
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    id1 = r.getrandbits(32)
    id2 = r.getrandbits(32)
    selfo = obj(c, 0x200, {0x2f0: stub(c, seq, 0, fld=_wf(c, _rf(c))), 0x130: _log130(c, id2)})
    c.emu.w32(selfo + 8, rnd(c, 0x80))
    c.emu.w32(selfo + 0xd6, r.getrandbits(32))
    _getsize(c, seq, [_rf(c), _rf(c), _rf(c)])

    C = obj(c, 0x40, {0x84: stub(c, seq, 1, ret=r.getrandbits(32))})
    T = obj(c, 0x40, {0x100: stub(c, seq, 1, ret=C)})
    M = obj(c, 0x40, {0x25c: stub(c, seq, 2, ret=T)})

    cnt = rnd(c, 4)
    c.emu.w32(cnt, r.randint(0, 3))
    Q = obj(c, 0x40, {0x4c: stub(c, seq, 1, skip=(0,)), 0x5c: _q5c(c, cnt, r.getrandbits(32))})
    obj24 = 0
    if r.random() < 0.9:
        obj24 = rnd(c, 0x40)
        c.emu.w32(obj24 + 0x18, Q if r.random() < 0.9 else 0)

    R = obj(c, 0xb00, {
        0x4c: stub(c, seq, 1, ret=r.getrandbits(32)),
        0x58: stub(c, seq, 1, ret=obj24),
        0x114: stub(c, seq, 4, ret=r.getrandbits(32),
                    retfn=[(0, 0x690438, id1 & 0xffff), (0, 0x6904a4, id2 & 0xffff)]),
    })
    c.emu.w32(R + 0xadc, M)
    sysobj(c, db=R)
    return [selfo]


S(0x513d10, 'ZMoveOnSpline::RegisterWithVisionSystem', 'thiscall', None, ret=None, gen=_gen,
  note='batch1646; GetSize hooked; slots 0x130 and 0x5c are raw code (logs and countdown)')
