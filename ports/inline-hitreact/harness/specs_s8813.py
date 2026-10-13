"""specs_s8813.py - hitreact batch 8813: the minimum-distance constraint 0x543680 and mmmul 0x4de440. PSVECSubtract, vaddscalar and
vmmul run as exe code; the engine random (slot 0x1c4) is a recording stub returning a per-case non-zero value."""
from pilot import S, F
from wkit import rnd, obj, fedge
from hkit import rec_stub, fvec


def _cycle_stub(c, vals):
    """thiscall (file, line), ret 8: loads vals[k % n] into ST0 on the k-th call; counts calls."""
    import struct
    n = len(vals)
    tab = c.emu.alloc(4 * n, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(tab + 4 * i, v)
    cnt = c.emu.alloc(4, 4)
    code = b'\xa1' + struct.pack('<I', cnt)                     # mov eax,[cnt]
    code += b'\x31\xd2\xb9' + struct.pack('<I', n) + b'\xf7\xf1'  # xor edx,edx; mov ecx,n; div ecx  (edx = cnt % n)
    code += b'\xd9\x04\x95' + struct.pack('<I', tab)             # fld dword [tab + edx*4]
    code += b'\xff\x05' + struct.pack('<I', cnt)                 # inc [cnt]
    code += b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _md(c):
    r = c.rng
    eng = obj(c, 0x200, {0x1c4: _cycle_stub(c, [r.uniform(-1, 1) or 0.25, r.uniform(-1, 1) or 0.5, r.uniform(-1, 1) or -0.75, 0.0, 0.0, 0.0][:3])})
    c.emu.w32(0x70039c, eng)
    A = [r.uniform(-100, 100) for _ in range(3)]
    k = r.random()
    if k < 0.15:
        B = list(A)                                      # coincident: the random direction loop
    elif k < 0.3:
        B = [A[i] + r.choice((1e-5, -2e-5, 3e-4, 1e-7)) for i in range(3)]   # lengths between 1e-6 and 1e-3
    elif k < 0.6:
        B = [A[i] + r.uniform(-10, 10) for i in range(3)]
    else:
        B = [r.uniform(-100, 100) for _ in range(3)]
    md = r.choice((5.0, 10.0, 15.0, 30.0, r.uniform(0, 50), fedge(c)))
    w = lambda: r.choice((1.0, 0.5, 0.0, 1e-4, r.uniform(0, 2)))
    c.emu.mu.ctl_flush_tb()
    return [fvec(c, A), fvec(c, B), F(w()), F(w()), F(md)]


S(0x543680, 'minimum-distance constraint', 'fastcall', ret=None, gen=_md)


def _mm(c):
    r = c.rng
    return [c.emu.alloc(48, 4), fvec(c, [r.uniform(-2, 2) for _ in range(9)]), fvec(c, [r.uniform(-2, 2) for _ in range(9)])]


S(0x4de440, 'mmmul', 'fastcall', ret=None, gen=_mm)
